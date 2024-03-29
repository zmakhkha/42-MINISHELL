/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wild_card.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:40:37 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/06 14:10:20 by ayel-fil         ###   ########.fr       */
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

char	*ft_tostr(t_str *src)
{
	char	*res;
	char	*tmp;

	res = NULL;
	tmp = NULL;
	if (!src || src->str == NULL)
		return (NULL);
	while (src)
	{
		tmp = ft_join_free(ft_strdup(src->str), ft_strdup(" "));
		res = ft_join_free(res, tmp);
		src = src->prev;
	}
	return (res);
}

void	ft__main_wc(t_str *r, t_str *b, char *str, int mode)
{
	if (!mode)
	{
		ft_free_str(&r);
		r = NULL;
		ft_free_str(&b);
		b = NULL;
	}
	if (mode)
	{
		if (r)
			ft_free_str(&r);
		if (b)
			ft_free_str(&b);
		b = NULL;
		free(str);
		str = NULL;
	}
}

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
		ft__main_wc(r, b, str, 0);
		return (str);
	}
	else
		ft__main_wc(r, b, str, 1);
	if (!ft_strcmp(res, ""))
		res = NULL;
	return (res);
}

char	*ft_rm_exp(char *str, t_env *env)
{
	int		i;
	int		t;
	char	*res;

	res = NULL;
	t = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
			t = 1;
		if (str[i] == '\"')
			t = 2;
		if (t)
			break ;
	}
	if (t == 1)
	{
		res = ft_rmsq(str);
	}
	else
		res = ft_rm__exp(str, env, res, i);
	if (str)
		free(str);
	return (res);
}
