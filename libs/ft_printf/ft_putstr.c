/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:52:34 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 11:29:49 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *string)
{
	int	len;

	len = 0;
	if (!string)
		return (write(1, "(null)", 6));
	while (*string)
		len += write(1, string++, 1);
	return (len);
}
