/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mult.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:20:39 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/15 16:03:42 by zmakhkha         ###   ########.fr       */
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
	t_str *s;

	s = NULL;
	ft_str_addback(&s, ft_add_str("min.c"));
	t_str *rs = ft_inter(src, s);

	while (rs)
	{
		puts(rs->str);
		rs = rs->prev;
	}
	
	return (NULL);
}