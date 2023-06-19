/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wild_card.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:40:37 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/19 10:42:41 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_strnstr1(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		s2;

	if (!haystack && !len)
		return (0);
	s2 = ft_strlen(needle);
	if (!needle || !s2)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] == haystack[i + j] && (i + j) < len)
			j++;
		if (j == s2)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
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
			res = src;
		else if (a == LEFT)
			res = ft_wc_left(src, prts[0]);
		else if (a == RIGHT)
			res = ft_wc_right(src, prts[0]);
		else if (a == MIDL)
			res = ft_middle(src, str);
		else if (a == MULT)
			res = ft_multi(src, str);
	}
	return (res);
}

// # define LEFT 0
// # define RIGHT 1
// # define MULT 2
// # define ALONE 2

char	*ft_tostr(t_str *src)
{
	char	*res;
	char	*tmp;

	res = NULL;
	while (src)
	{
		tmp = ft_join_free(src->str, "\t");
		res = ft_join_free(res, tmp);
		src = src->prev;
	}
	return (res);
}

void	ft_free_env(t_env **list)
{
	t_env	*lst;

	lst = *list;
	if (list && lst)
	{
		ft_free_env(&(lst->next));
		if (lst->key)
		{
			free (lst->key);
			lst->key = NULL;
		}
		if (lst->value)
		{
			free (lst->value);
			lst->value = NULL;
		}
		free (lst);
		lst = NULL;
	}
}

// to be called foreach node
char	*ft_main_wc(char	*str, t_env	*env_list)
{
	t_str	*r;
	t_str	*b;
	char	*res;

	res = NULL;
	if (strrchr(str, '*'))
	{
		r = ft_dirfiles(env_list);
		b = ft_matching(r, str);
		res = ft_tostr(b);
	}
	ft_free_str(&r);
	return (res);
}