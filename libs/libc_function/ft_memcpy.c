/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:16:38 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 15:29:09 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_c.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str1;
	char	*str2;

	if (dst == src)
		return (dst);
	str1 = (char *)dst;
	str2 = (char *)src;
	while (n > 0)
	{
		*str1 = *str2;
		str1 += 1;
		str2 += 1;
		n -= 1;
	}
	return (dst);
}
