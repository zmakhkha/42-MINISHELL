/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:01:11 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 18:12:08 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_c.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hay_index;
	size_t	ne_index;

	if (!haystack && len == 0)
		return (NULL);
	hay_index = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[hay_index] && hay_index < len)
	{
		ne_index = 0;
		while (hay_index + ne_index < len && needle[ne_index]
			&& haystack[hay_index + ne_index] && haystack[hay_index
				+ ne_index] == needle[ne_index])
			ne_index++;
		if (needle[ne_index] == '\0')
			return ((char *)&haystack[hay_index]);
		hay_index++;
	}
	return (NULL);
}
