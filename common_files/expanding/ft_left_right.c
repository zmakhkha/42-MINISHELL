/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:17:06 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 16:38:24 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_str	*ft_wc_left(t_str *src, char *cnd)
{
	t_str	*res;
	int		i;
	int		m;
	int		len;

	len = ft_strlen(cnd);
	i = 0;
	res = NULL;
	m = ft_count_lmatching(src, cnd);
	if (m)
	{
		while (src)
		{
			i = 0;
			while ((i < len) && src->str[i] \
			&& (src->str[i] == cnd[i]))
				i++;
			if (i == len)
				ft_str_addback(&res, ft_add_str(ft_strdup(src->str)));
			src = src->prev;
		}
	}
	return (res);
}

int	ft_count_rmatching(t_str *src, char *cnd)
{
	int	m;
	int	len1;
	int	len2;

	m = 0;
	if (src && cnd)
	{
		while (src)
		{
			len2 = ft_strlen(cnd);
			len1 = ft_strlen(src->str);
			while ((len1 > 0) && (len2 > 0) && \
			cnd[len2 - 1] == src->str[len1 - 1])
			{
				len1--;
				len2--;
			}
			if (len2 == 0)
				m++;
			src = src->prev;
		}
	}
	return (m);
}

t_str	*ft_wc_right(t_str *src, char *cnd)
{	
	int		len1;
	int		len2;
	t_str	*res;
	int		m;

	res = NULL;
	m = ft_count_rmatching(src, cnd);
	if (m)
	{
		while (src)
		{
			len1 = ft_strlen(src->str);
			len2 = ft_strlen(cnd);
			while ((len1 >= 1) && (len2 >= 1) \
			&& cnd[len2 - 1] == src->str[len1 - 1])
			{
				len1--;
				len2--;
			}
			if (len2 == 0)
				ft_str_addback(&res, ft_add_str(ft_strdup(src->str)));
			src = src->prev;
		}
	}
	return (res);
}

int	ft__count(char *str, int c, int i)
{
	if (c == 1)
	{
		if (ft_strlen(str) == 1)
			return (ALONE);
		else if (*str == '*')
			return (RIGHT);
		else if (str[i - 1] == '*')
			return (LEFT);
		else
			return (MIDL);
	}
	else if (c > 1)
		return (MULT);
	return (0);
}

int	ft_count(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '*')
			{
				c++;
			}
			i++;
		}
	}
	return (ft__count(str, c, i));
	return (0);
}
