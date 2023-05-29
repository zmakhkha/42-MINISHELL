/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:45:42 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 18:10:32 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, string);
	i = 0;
	len = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			len += ft_handler(string[i + 1], args);
			i++;
		}
		else
			len += ft_putchar(string[i]);
		i++;
	}
	va_end(args);
	return (len);
}
