/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:24:24 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 15:29:31 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_c.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1 += 1;
		s2 += 1;
		n -= 1;
	}
	return (0);
}
