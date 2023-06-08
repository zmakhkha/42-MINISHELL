/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:01:45 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 15:29:22 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_c.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1lenght;

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
