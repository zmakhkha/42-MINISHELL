/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:11:44 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/18 17:21:38 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	l1;
	int	l2;

	i = -1;
	if (s1 && s2)
	{
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		if (l1 != l2)
			return (i);
		while (l1 && s1[l1] == s2[l1])
			l1--;
		return (s1[l1] - s2[l1]);
	}
	return (-1);
}
