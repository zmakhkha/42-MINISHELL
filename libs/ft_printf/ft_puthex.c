/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:02 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 11:29:49 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, const char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, base);
	len += ft_putchar((char)(base[n % 16]));
	return (len);
}
