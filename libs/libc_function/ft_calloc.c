/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:58:07 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 15:29:00 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_c.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	total = count * size;
	if (count && total / count != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, total);
	return (ptr);
}
