/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 02:49:48 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/22 14:25:37 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	ft_lstclear(t_env **lst, void (*del)(void *))
{
	t_env	*ptr;
	t_env	*tmp;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr->next;
		del(ptr->key);
		free(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}
