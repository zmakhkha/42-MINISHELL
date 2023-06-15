/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:17:06 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/15 13:20:18 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_count_lmatching(t_str *src, char *cnd)
{
	int	m;
	int	i;

	i = 0;
	m = 0;
	if (src && cnd)
	{
		while (src)
		{
			while (src->str[i] && (src->str[i] == cnd[i]) \
			&& (cnd[i] != '*'))
				i++;
			if (cnd[i] == '*')
				m++;
			src = src->prev;
		}
	}
	return (m);
}

t_str	*ft_wc_left(t_str *src, char *cnd)
{
	t_str	*res;
	int		i;
	int		m;

	i = 0;
	res = NULL;
	m = ft_count_lmatching(src, cnd);
	if (m)
	{
		while (src)
		{
			i = 0;
			while (src->str[i] && (src->str[i] == cnd[i]) \
			&& (cnd[i] != '*'))
				i++;
			if (cnd[i] == '*')
				ft_str_addback(&res, ft_add_str(src->str));
			src = src->prev;
		}
	}
	return (res);
}

int	ft_count_rmatching(t_str *src, char *cnd, int len1, int len2)
{
	int	m;

	m = 0;
	if (src && cnd)
	{
		while (src)
		{
			len1 = ft_strlen(src->str);
			len2 = ft_strlen(cnd);
			while ((len1 - 1 >= 0) && src->str[len1 - 1] \
			&& (src->str[len1 - 1] == cnd[len2 - 1]) \
			&& (cnd[len2 - 1] != '*'))
			{
				len1--;
				len2--;
			}
			if (cnd[len2 - 1] == '*')
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
	int		j;
	t_str	*res;
	int		m;

	m = 0;
	j = 0;
	len1 = 0;
	len2 = 0;
	res = NULL;
	m = ft_count_rmatching(src, cnd, len1, len2);
	if (m)
	{
		while (src)
		{
			len1 = ft_strlen(src->str);
			len2 = ft_strlen(cnd);
			while ((len1 - 1 >= 0) && src->str[len1 - 1] \
			&& (src->str[len1 - 1] == cnd[len2 - 1]) \
			&& (cnd[len2 - 1] != '*'))
			{
				len1--;
				len2--;
			}
			if (cnd[len2 - 1] == '*')
				ft_str_addback(&res, ft_add_str(src->str));
			src = src->prev;
		}
	}
	return (res);
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
			if (str[i++] == '*')
				c++;
		}
	}
	if (c == 1 && *str == '*')
		return (RIGHT);
	else if (c == 1 && str[i - 1] == '*')
		return (LEFT);
	else if (c >= 1)
		return (MULT);
	return (0);
}
