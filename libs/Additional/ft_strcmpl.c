/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 05:47:23 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/24 05:52:06 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional.h"

int	ft_strcmpl(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] || s2[i])
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			return (1);
		i++;
	}
	return (0);
}