/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:58:46 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 18:01:24 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional.h"

double	ft_dtof(const char *str, int fraction)
{
	double	result;

	result = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			result = result * 10 + (*str - '0');
			fraction *= 10;
			str++;
		}
	}
	return (result / fraction);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	result;
	double	fraction;

	sign = 0;
	sign = POSITIVE;
	result = 0;
	fraction = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		sign = NEGATIVE;
	}
	else if (*str == '+')
		str++;
	result = ft_dtof(str, fraction);
	return (sign * result);
}
