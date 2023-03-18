/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:54:38 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/17 10:54:38 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_voperator(char*str, char op)
{
	int	i;

	i = 0;
	if (str[i] && str[i + 1] && str [i + 2])
	{
		if (str[i] == op && str[i + 1] == op && str[i + 2] == op)
			return (0);
	}
	if (str[i] && str[i + 1])
	{
		if (str[i] == op || str[i + 1] == op)
			return (1);
	}
	if (str[i])
	{
		if (str[i] == '&')
			return (0);
		else if (str[i] == op)
			return (1);
	}
	return (0);
}

int	ft_validouble(char *str, char op)
{
	int	i;

	i = 0;
	if (str[i] && str[i + 1])
	{
		if (str[i] == op && str[i + 1] == op)
			return (1);
		else
			return (0);
	}
	return (0);
}
