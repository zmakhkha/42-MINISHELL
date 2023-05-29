/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:43:00 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 15:58:09 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add.h"

static size_t	min(size_t a, size_t b)
{
	return (a * (a < b) + b * (b <= a));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	string_len;
	char	*string;

	if (!s)
		return (NULL);
	string_len = ft_strlen(s);
	if (start >= string_len)
		return (ft_strdup(""));
	string = ft_calloc((min(string_len - start, len) + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	ft_memcpy(string, s + start, min(string_len - start, len));
	return (string);
}
