/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:14:57 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 15:57:33 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*g_string;
	int		s1lenght;
	int		s2lenght;
	int		total;

	if (!s1 || !s2)
		return (0);
	s1lenght = ft_strlen(s1);
	s2lenght = ft_strlen(s2);
	total = s1lenght + s2lenght + 1;
	g_string = ft_calloc(total, sizeof(char));
	if (g_string == NULL)
		return (g_string);
	ft_strlcat(g_string, s1, total);
	ft_strlcat(g_string, s2, total);
	return (g_string);
}
