/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:47:30 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/03/15 01:10:23 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int))
{
	t_stack	*new_lest;
	t_stack	*chunk;

	if (!f || !del)
		return (0);
	new_lest = NULL;
	while (lst)
	{
		chunk = ft_lstnew(f(lst->content));
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
