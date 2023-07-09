/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:30:34 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 11:37:15 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handler(char character, va_list args)
{
	int	len;

	len = 0;
	if (character == 'd' || character == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (character == 'x')
		len += ft_puthex(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (character == 'X')
		len += ft_puthex(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (character == 'u')
		len += ft_putnbr_u(va_arg(args, unsigned int));
	else if (character == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (character == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (character == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putaddress(va_arg(args, unsigned long long));
	}
	else if (character == '%')
		len += ft_putchar('%');
	return (len);
}
