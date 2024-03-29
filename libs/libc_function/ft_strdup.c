/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:01:45 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/05 12:22:29 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_c.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1lenght;

	if (!s1)
		return (NULL);
	s1lenght = ft_strlen(s1);
	ptr = ft_calloc(s1lenght + 1, sizeof(char));
	if (!ptr)
	{
		free(ptr);
		return (ptr);
	}
	ft_memcpy(ptr, s1, (s1lenght * sizeof(char)));
	return (ptr);
}
