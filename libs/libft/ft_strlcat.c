/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:00:31 by ayel-fil          #+#    #+#             */
/*   Updated: 2022/11/09 09:51:54 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclenght;
	size_t	dstlenght;
	size_t	i;
	char	*source;

	srclenght = ft_strlen(src);
	source = (char *)src;
	if (dstsize == 0)
		return (srclenght);
	dstlenght = ft_strlen(dst);
	i = dstlenght;
	if (dstlenght >= dstsize)
		return (srclenght + dstsize);
	while (i < dstsize - 1 && *source)
	{
		dst[i] = *source++;
		i += 1;
	}
	dst[i] = '\0';
	return (srclenght + dstlenght);
}
