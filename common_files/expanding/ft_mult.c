/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:20:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/24 12:51:47 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_strlen2(char **str)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (str[++i])
		len++;
	return (len);
}

t_str	*ft___multi(t_str *res, char *cnd, char **parts)
{
	int		len;
	int		len1;
	t_str	*tmp;

	len1 = ft_strlen2(parts);
	len = ft_strlen(cnd);
	tmp = res;
	if (cnd[0] != '*')
		tmp = ft_wc_left(tmp, parts[0]);
	if (cnd[len - 1] != '*')
		tmp = ft_wc_right(tmp, parts[len1 - 1]);
		ft_free_str(&res);
	return (tmp);
}

t_str	*ft__multi(t_str *src, char **parts, t_str *res)
{
	int		i;
	int		len;
	char	*tmp;

	len = ft_strlen2(parts);
	while (src)
	{
		i = 0;
		tmp = src->str;
		while (tmp && parts[i] && ft_strnstr1(tmp, parts[i], ft_strlen(tmp)))
		{
			tmp = ft_strnstr1(tmp, parts[i], ft_strlen(tmp));
			i++;
		}
		if (i == len && ft_strnstr1(tmp, parts[i - 1], ft_strlen(tmp)))
			ft_str_addback(&res, ft_add_str(ft_strdup(src->str)));
		src = src->prev;
	}
	return (res);
}

t_str	*ft_multi(t_str *src, char *cnd)
{
	char	**parts;
	t_str	*res;
	int		len;

	parts = ft_split(cnd, '*');
	res = NULL;
	if (!parts)
		ft_exit("Allocation error ", 1);
	len = ft_strlen2(parts);
	res = ft__multi(src, parts, res);
	res = ft___multi(res, cnd, parts);
	ft_free_2dstr(parts);
	return (res);
}

t_str	*ft_middle(t_str *src, char *cnd)
{
	t_str	*l_match;
	t_str	*r_match;
	char	**parts;

	l_match = NULL;
	r_match = NULL;
	parts = ft_split(cnd, '*');
	if (src && cnd)
	{
		l_match = ft_wc_left(src, parts[0]);
		r_match = ft_wc_right(l_match, parts[1]);
	}
	ft_free_2dstr(parts);
	ft_free_str(&l_match);
	return (r_match);
}
