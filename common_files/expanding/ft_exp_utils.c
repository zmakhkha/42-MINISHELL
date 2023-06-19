/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:45:00 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/19 16:56:54 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_join_freel(char *s1, char *s2, int len)
{
	size_t	l1;
	int		i;
	char	*res;

	res = NULL;
	if (s1 && s2)
	{
		l1 = ft_strlen(s1);
		res = (char *)malloc(l1 + len + 1);
		i = -1;
		while (++i < (int)l1)
			res[i] = s1[i];
		i = -1;
		while (++i < len)
			res[l1 + i] = s2[i];
		res[l1 + i] = '\0';
		free(s1);
	}
	return (res);
}

char	*ft__rmsq(char *str, int i, int len, int c)
{
	char	*res;

	res = NULL;
	res = malloc(len + 1);
	if (!res)
		ft_exit("Allocation error !!", 1);
	i = -1;
	len = -1;
	while (str[++i])
	{
		if (str[i] != c)
			res[++len] = str[i];
	}
	res[len + 1] = 0;
	return (res);
}

char	*ft__rmsq2(char *str, int len, char c)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_rmsq(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = 0;
	while (str[i] && (str[i] != '\'' && str[i] != '\"'))
		i++;
	if (str[i])
		c = str[i];
	else
		return (ft_strdup(str));
	i = -1;
	while (str[++i])
	{
		if (str[i] != c)
			len++;
	}
	return (ft__rmsq2(str, len, c));
}

void	ft_merge_all(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst && lst->prev)
	{
		if (lst->str && lst->prev->str)
		{
			s_tmp = ft_join_free(lst->str, lst->prev->str);
			free(lst->str);
			lst->str = s_tmp;
			lst->type = WORD;
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
	lst = *list;
}
