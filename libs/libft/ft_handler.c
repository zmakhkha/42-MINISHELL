/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:30:34 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/01/29 05:52:58 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handler(char charachter, va_list args)
{
	int	len;

	len = 0;
	if (charachter == 'd' || charachter == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (charachter == 'x')
		len += ft_puthex(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (charachter == 'X')
		len += ft_puthex(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (charachter == 'u')
		len += ft_putnbr_u(va_arg(args, unsigned int));
	else if (charachter == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (charachter == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (charachter == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putaddress(va_arg(args, unsigned long long));
	}
	else if (charachter == '%')
		len += ft_putchar('%');
	return (len);
}
