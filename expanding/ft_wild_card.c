/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wild_card.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:40:37 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/15 13:27:05 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_str	*ft_matching(t_str *src, char *str)
{
	int		a;
	t_str	*res;

	a = -1;
	res = NULL;
	if (str && src)
	{
		a = ft_count(str);
		if (a == LEFT)
			res = ft_wc_left(src, str);
		else if (a == RIGHT)
			res = ft_wc_right(src, str);
		else if (a != -1)
			ft_multi(src, str);
	}
	return (res);
}

// # define LEFT 0
// # define RIGHT 1
// # define MULT 2



void	ft_main_wc(char	*str, t_env	*env_list)
{
	t_str	*r;
	t_str	*b;

	if (strrchr(str, '*'))
	{
		r = ft_dirfiles(env_list);
		b = ft_matching(r, str);
		while (b)
		{
			puts(b->str);
			b = b->prev;
		}
	}
}
