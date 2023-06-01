/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:01:25 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 15:29:05 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_c.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	character;

	string = (unsigned char *)s;
	character = (unsigned char)c;
	while (n > 0 && *string != character)
	{
		string += 1;
		n -= 1;
	}
	if (n == 0)
		return (0);
	return ((void *)string);
}
