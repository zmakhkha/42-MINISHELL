/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:24:04 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/28 15:24:48 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_lststrlen(t_token *lst)
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
		printf("(%s, %d)->", list->str, list->type);
		ft_print_tree(list->right);
	}
}
