/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:00:31 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 15:28:56 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_c.h"

static int	count_digits(long n)
{
	if (n < 0)
		return (count_digits(n * -1) + 1);
	if (n < 10)
		return (1);
	return (count_digits(n / 10) + 1);
}

static char	*convert_to_string(char *string, long nb, int lenght)
{
	while (lenght > 0)
	{
		string[lenght - 1] = (nb % 10) + 48;
		nb /= 10;
		lenght--;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		lenght;
	int		sign;
	long	nb;

	sign = POSITIVE;
	nb = n;
	lenght = count_digits(n);
	string = ft_calloc(lenght + 1, sizeof(char));
	if (string == NULL)
		return (0);
	if (nb == 0)
		string[0] = '0';
	if (nb < 0)
	{
		sign = NEGATIVE;
		nb = -nb;
	}
	string = convert_to_string(string, nb, lenght);
	if (sign == NEGATIVE)
		string[0] = '-';
	return (string);
}
