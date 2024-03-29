/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtotree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:29:03 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 23:26:28 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_sub_ast(t_token **list)
{
	ft_make_bigops(list);
	ft_pipe_nodes(list);
	ft_leaf_nodes(list);
}

void	ft__subtotree(t_token **list)
{
	t_token	*lst;
	t_token	*t;

	lst = *list;
	ft_subtotree(&lst->left);
	if (lst->type == SUBSHELL)
	{
		t = ft_strtok(lst->str);
		if (!g_glob.g_status && t)
			ft_main_lexer(t);
		else if (t)
		{
			printf("Lexer Error !!\n");
			return ;
		}
		if (!g_glob.g_status && t)
		{
			ft_sub_ast(&t);
			*list = t;
		}
		else if (t)
			printf("Parser Error !!\n");
	}
}

void	ft_subtotree(t_token **list)
{
	if (list && *list)
	{	
		ft__subtotree(list);
		ft_subtotree(&(*list)->right);
	}
}
