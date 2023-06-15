/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:20:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/15 19:00:33 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_str	*ft_inter(t_str *s1, t_str *s2)
{
	t_str	*res;

	res = NULL;
	while(s1 && s2)
	{
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

t_str	*ft_multi(t_str *src, char *cnd)
{
	(void)src;
	(void)cnd;
	// char	**parts;

	// while(src)
	// {
		
	// }
	
	return (NULL);
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