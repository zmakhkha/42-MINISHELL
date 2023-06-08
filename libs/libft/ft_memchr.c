/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:01:25 by ayel-fil          #+#    #+#             */
/*   Updated: 2022/11/03 10:02:35 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
