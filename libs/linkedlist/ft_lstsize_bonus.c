/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:29:51 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/22 14:24:09 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

int	ft_lstsize(t_env *lst)
{
	int	index;

	index = 0;
	while (lst)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}
