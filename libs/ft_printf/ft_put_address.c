/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:40:10 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 11:29:49 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress(unsigned long long n)
{
	int			len;
	const char	*base;

	base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_putaddress(n / 16);
	len += ft_putchar((char)base[n % 16]);
	return (len);
}
