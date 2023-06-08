/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:54:22 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 15:57:40 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*string;
	int		s_lenght;

	if (!s || !f)
		return (0);
	s_lenght = ft_strlen(s);
	string = ft_calloc(s_lenght + 1, sizeof(char));
	if (!string)
		return (string);
	i = 0;
	while (s[i] != '\0')
	{
		string[i] = f(i, s[i]);
		i++;
	}
	return (string);
}
