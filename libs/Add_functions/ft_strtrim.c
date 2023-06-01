/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:58:42 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 15:58:03 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start += 1;
	while (end >= 0 && ft_strchr(set, s1[end - 1]) != NULL)
		end -= 1;
	str = ft_substr(s1, start, end - start);
	return (str);
}
