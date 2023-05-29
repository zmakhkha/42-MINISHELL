/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 08:56:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2022/11/06 11:10:07 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str1;
	char	*str2;

	if (dst == src)
		return (dst);
	str1 = (char *)dst;
	str2 = (char *)src;
	if (dst < src)
		return (ft_memcpy(str1, str2, len));
	while ((str2 || str1) && len > 0)
	{
		--len;
		str1[len] = str2[len];
	}
	return (dst);
}
