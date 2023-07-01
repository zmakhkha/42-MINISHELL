/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subtotree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:29:03 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/01 12:26:49 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_sub_ast(t_token **list)
{
	ft_make_bigops(list);
	ft_pipe_nodes(list);
	ft_leaf_nodes(list);
}

void	ft_subtotree(t_token **list)
{
	t_token	*lst;
	t_token	*t;

	if (list && *list)
	{
		lst = *list;
		ft_subtotree(&lst->left);
		if (lst->type == SUBSHELL)
		{
			t = ft_strtok(lst->str);

			if (!glob.g_status && t)
				ft_main_lexer(t);
			else if (t)
			{
				printf("Lexer Error !!\n");
				return ;
			}
			if (!glob.g_status && t)
			{
				ft_sub_ast(&t);
				*list = t;
			}
			else if (t)
				printf("Parser Error !!\n");
		}
		ft_subtotree(&lst->right);
	}
}
