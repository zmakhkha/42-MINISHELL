/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leafs_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:53:18 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/28 17:59:25 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_token	*ft_makenull(void)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		ft_exit("Allocation failed !!", 1);
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	node->prev = NULL;
	node->str = NULL;
	node->type = Empty;
	return (node);
}

t_token	*ft_make_leafs(t_token **list)
{
	t_token	*tmp;
	t_token	*last;
	t_token	*first;

	tmp = NULL;
	if (list && *list)
	{
		if (ft_lstlen(*list) > 1)
		{
			tmp = ft_makenull();
			first = ft_getfirst(*list);
			last = ft_pop(list);
			tmp->right = last;
			tmp->left = first;
			*list = tmp;
		}
		ft_make_leafs(&(*list)->left);
		ft_make_leafs(&(*list)->right);
	}
	return (*list);
}

// To handle multiples erdirection in a simple command
void	ft_leaf_nodes(t_token **list)
{
	if (list && *list)
	{
		ft_leaf_nodes(&(*list)->left);
		ft_leaf_nodes(&(*list)->right);
		if ((*list)->left && ft_lstlen((*list)->left) > 1)
			(*list)->left = ft_make_leafs(&(*list)->left);
		if ((*list)->right && ft_lstlen((*list)->right) > 1)
			(*list)->right = ft_make_leafs(&(*list)->right);
		if (ft_lstlen(*list) > 1)
			*list = ft_make_leafs(list);
	}
}
