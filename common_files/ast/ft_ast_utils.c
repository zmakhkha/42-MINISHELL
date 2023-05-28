/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:24:04 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/28 19:07:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_lstlen(t_token *lst)
{
	int	i;

	i = 0;
	lst = ft_getfirst(lst);
	while (lst)
	{
		i += 1;
		lst = lst->prev;
	}
	return (i);
}

void	ft_print_tree(t_token *list)
{
	if (list)
	{
		ft_print_tree(list->left);
		printf("(%s)->", list->str);
		ft_print_tree(list->right);
	}
}

t_token	*ft_pop(t_token **list)
{
	t_token	*last;

	last = NULL;
	if (list && *list)
	{
		last = ft_getlast(*list);
		if (last->next)
			last->next->prev = NULL;
		last->next = NULL;
		last->right = NULL;
		last->left = NULL;
	}
	return (last);
}

void	ft_free_tree(t_token **list)
{
	if (list && *list)
	{
		ft_free_tree(&(*list)->prev);
		ft_free_tree(&(*list)->left);
		ft_free_tree(&(*list)->right);
		if ((*list)->str)
			free ((*list)->str);
		(*list)->str = NULL;
		free(*list);
		*list = NULL;
		list = NULL;
	}
}
