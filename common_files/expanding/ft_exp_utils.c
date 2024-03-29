/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:45:00 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 19:51:32 by zmakhkha         ###   ########.fr       */
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
		if (!res)
			return (NULL);
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
	str = NULL;
	return (res);
}

char	*ft_rmsq(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = 0;
	while (str[i] && (str[i] != '\"'))
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

int	ft_count_lmatching(t_str *src, char *cnd)
{
	int	m;
	int	i;
	int	len1;

	m = 0;
	len1 = ft_strlen(cnd);
	if (src && cnd)
	{
		while (src)
		{
			i = 0;
			while (i < len1 && src->str[i] && \
			(src->str[i] == cnd[i]))
				i++;
			if (i == len1)
				m++;
			src = src->prev;
		}
	}
	return (m);
}

// void	ft_merge_all(t_token **list)
// {
// 	t_token	*lst;
// 	char	*s_tmp;

// 	lst = *list;
// 	while (lst && lst->prev)
// 	{
// 		if (lst->str && lst->prev->str)
// 		{
// 			s_tmp = ft_join_free(lst->str, lst->prev->str);
// 			free(lst->str);
// 			lst->str = s_tmp;
// 			lst->type = WORD;
// 			ft_remove_tok(list, lst->prev);
// 			continue ;
// 		}
// 		lst = lst->prev;
// 	}
// 	lst = *list;
// }
