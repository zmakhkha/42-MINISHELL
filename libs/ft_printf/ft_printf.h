/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:02:22 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 18:10:38 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> /* for variadic functions */
# include <unistd.h> /* system call functions */

/*  *************** ft_printf ************** */
int	ft_putchar(int c);
int	ft_putnbr(int n);
int	ft_putstr(char *string);
int	ft_puthex(unsigned int n, const char *base);
int	ft_putnbr_u(unsigned int n);
int	ft_putaddress(unsigned long long n);
int	ft_printf(const char *string, ...);
int	ft_handler(char character, va_list args);
#endif