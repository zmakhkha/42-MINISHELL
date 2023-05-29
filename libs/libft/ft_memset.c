/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:49:30 by ayel-fil          #+#    #+#             */
/*   Updated: 2022/11/03 10:03:25 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*s;

	s = b;
	i = 0;
	while (len > 0)
	{
		s[i] = (unsigned char)c;
		i += 1;
		len -= 1;
	}
	return (b);
}
