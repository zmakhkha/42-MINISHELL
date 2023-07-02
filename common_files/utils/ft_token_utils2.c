/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:18:05 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/30 12:49:31 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_position_it(t_token **lst)
{
	int		i;
	t_token	*pos;

	i = 0;
	if (lst && *lst)
	{
		pos = *lst;
		while (pos)
		{
			pos->index = i;
			i++;
			pos = pos->prev;
		}
	}
}

void	ft_remove_tok(t_token **list, t_token *node)
{
	if (*list == node)
		*list = node->prev;
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	free(node->str);
	node->str = NULL;
	free(node);
	node = NULL;
}

void	ft_swap(t_token *lst)
{
	t_token	*t_next;
	t_token	*t_prev;
	t_token	*tmp;

	t_prev = lst->prev;
	t_next = lst->next;
	tmp = t_prev->prev;
	if (!t_prev && !t_next)
	{
	}
	else if (lst && t_prev)
	{
		if (t_next)
			t_next->prev = lst->prev;
		lst->prev = t_prev->prev;
		t_prev->next = t_next;
		t_prev->prev = lst;
		lst->next = t_prev;
		if (tmp)
			tmp->next = lst;
	}
}
