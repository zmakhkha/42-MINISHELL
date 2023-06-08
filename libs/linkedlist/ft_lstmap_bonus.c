/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:47:30 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/22 14:29:35 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_env	*ft_lstmap(t_env *lst, void *(*f)(void *), void (*del)(void *))
{
	t_env	*new_lest;
	t_env	*chunk;

	if (!f || !del)
		return (0);
	new_lest = NULL;
	while (lst)
	{
		chunk = ft_lstnew(f(lst->key),f(lst->value));
		if (chunk == NULL)
		{
			ft_lstclear(&new_lest, del);
			return (0);
		}
		ft_lstadd_back(&new_lest, chunk);
		lst = lst->next;
	}
	return (new_lest);
}
