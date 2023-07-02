/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wild_card.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:40:37 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 17:17:25 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

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

// # define LEFT 0
// # define RIGHT 1
// # define MULT 2
// # define ALONE 2

char	*ft_tostr(t_str *src)
{
	char	*res;
	char	*res_;
	char	*tmp;

	res = NULL;
	res_ = NULL;
	tmp = NULL;
	while (src)
	{
		tmp = ft_join_free(ft_strdup(src->str), ft_strdup(" "));
		res = ft_join_free(res, tmp);
		src = src->prev;
	}
	return (res);
}

// void	ft_free_obj(t_str **s)
// {
// 	if (s)
// 	{
// 		ft_free_obj(&(*s)->prev);
// 		free(*s);
// 		s = NULL;
// 	}
// }

// to be called foreach node
char	*ft_main_wc(char *str, t_env *env_list)
{
	char	*res;
	t_str	*r;
	t_str	*b;

	res = NULL;
	r = NULL;
	b = NULL;
	if (strrchr(str, '*'))
	{
		r = ft_dirfiles(env_list);
		b = ft_matching(r, str);
		res = ft_tostr(b);
	}
	if (!res)
	{
		ft_free_str(&r);
		r = NULL;
		ft_free_str(&b);
		b = NULL;
		free(str);
		str = NULL;
		return (str);
	}
	else
	{
		if (r)
			ft_free_str(&r);
		if (b)
			ft_free_str(&b);
		b = NULL;
		if (str)
			free(str);
		str = NULL;
	}
	return (res);
}
