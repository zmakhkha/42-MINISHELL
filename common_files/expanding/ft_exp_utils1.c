/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:41:47 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 19:21:26 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_isquote(char *str)
{
	if (str)
	{
		while (str)
		{
			if ((*str) == '\'' || (*str) == '\"')
				return (1);
		}
	}
	return (0);
}

char	**ft_format(char *str)
{
	char	**spl;

	spl = ft_split(str, ' ');
	if (str)
		free(str);
	str = NULL;
	return (spl);
}

void	ft_strrep(char *str, char a, char b)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == a)
			str[i] = b;
	}
}

t_str	*ft_strmkcpy(t_str *src)
{
	t_str	*res;

	res = NULL;
	while (src)
	{
		ft_str_addback(&res, (ft_add_str(ft_strdup(src->str))));
		src = src->prev;
	}
	return (res);
}

t_str	*ft_matching(t_str *src, char *str)
{
	int		a;
	t_str	*res;
	char	**prts;

	prts = ft_split(str, '*');
	a = -1;
	res = NULL;
	a = ft_count(str);
	if (str && src)
	{
		if (a == ALONE)
			res = ft_strmkcpy(src);
		else if (a == LEFT)
			res = ft_wc_left(src, prts[0]);
		else if (a == RIGHT)
			res = ft_wc_right(src, prts[0]);
		else if (a == MIDL)
			res = ft_middle(src, str);
		else if (a == MULT)
			res = ft_multi(src, str);
	}
	ft_free_2dstr(prts);
	return (res);
}
