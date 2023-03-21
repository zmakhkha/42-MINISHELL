/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:58:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/21 19:20:02 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_create(t_tree *tree)
{
	tree = NULL;
}

void	ft_delete(t_tree *tree)
{
	if (tree)
	{
		ft_delete(tree->left);
		ft_delete(tree->right);
		free(tree);
	}
}

void	ft_mleft(t_tree *tree)
{
	if (tree)
	{
		ft_mleft(tree->left);
		printf("%s", tree->str[0]);
		ft_mleft(tree->right);
	}
}
