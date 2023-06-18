/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:20:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/18 13:57:06 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// intersection of s1 and s2 in res
t_str	*ft_inter(t_str *s1, t_str *s2)
{
	t_str	*res;
	t_str	*ts1;

	res = NULL;
	ts1 = s1;
	while(s1 && s2)
	{
		s1 = ts1;
		while (s1)
		{
			if (!ft_strcmplen(s1->str, s2->str))
			ft_str_addback(&res, ft_add_str(s1->str));
			s1 = s1->prev;
		}
			s2 = s2->prev;
	}
	return (res);
}

int	ft_strlen2(char **str)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while(str[++i])
		len++;
	return (len);
}

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

t_str	*ft__multi(t_str *res, char *cnd, char **parts)
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
		return (tmp);
}

t_str	*ft_multi(t_str *src, char *cnd)
{
	char	**parts;
	t_str	*res;
	char	*tmp;
	int		i;
	int		len;
	parts = ft_split(cnd, '*');
	res = NULL;
	if (!parts)
		ft_exit("Allocation error ", 1);
	len = ft_strlen2(parts);
	while(src)
	{
		i = 0;
		tmp = src->str;
		while (tmp && parts[i] && ft_strnstr1(tmp, parts[i], ft_strlen(tmp)))
		{
			tmp = ft_strnstr1(tmp, parts[i], ft_strlen(tmp));
			i++;
		}
		if (i == len && ft_strnstr1(tmp, parts[i - 1], ft_strlen(tmp)))
			ft_str_addback(&res, ft_add_str(src->str));
		src = src->prev;
	}
	res = ft__multi(res, cnd, parts);
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
		r_match = ft_wc_right(src, parts[1]);
	}

	while(l_match)
	{
		puts(l_match->str);
		l_match = l_match ->prev;
	}
	
	
	return (NULL);
}