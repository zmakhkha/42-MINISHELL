/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:11:37 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/24 18:14:59 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_c.h"

long int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	char	*string;

	sign = POSITIVE;
	string = (char *)str;
	result = 0;
	while (ft_isspace(*string))
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign = NEGATIVE;
		string++;
	}
	while (ft_isdigit(*string))
	{
		result = (*string - '0') + result * 10;
		string++;
	}
	return (result * sign);
}
