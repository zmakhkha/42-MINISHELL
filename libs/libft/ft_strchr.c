/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:46:34 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/03 10:50:31 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*string;
	char	character;

	string = (char *)s;
	character = (char)c;
	if (!s)
		return (NULL);
	while (*string != character)
	{
		if (*string == '\0')
		{
			if (c == 0)
				return (string);
			return (NULL);
		}
		string += 1;
	}
	return (string);
}
