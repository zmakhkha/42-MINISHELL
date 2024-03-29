/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:58:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/07 03:08:33 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_printini(t_token **list)
{
	t_token	*lst;

	lst = *list;
	if (list && *list)
	{
		ft_printini(&lst->left);
		printf("(%d, %s)", lst->type, lst->str);
		ft_printini(&lst->right);
	}
}

void	ft_main_ast(t_token **list, t_env **env_list)
{
	ft_make_bigops(list);
	ft_pipe_nodes(list);
	ft_leaf_nodes(list);
	ft_subtotree(list);
	ft_hdocontree(list, env_list);
	ft_exe_tree(*list, env_list);
}
