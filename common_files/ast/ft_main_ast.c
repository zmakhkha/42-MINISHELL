/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:58:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/21 11:08:12 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// void	ft_printini(t_token **list )
// {
// 	t_token	*lst;

// 	lst = *list;
// 	if (list && *list)
// 	{
// 		ft_printini(&lst->left);
// 		printf("(%d, %s)", lst->type, lst->str);
// 		ft_printini(&lst->right);
// 	}
// }


void	ft_main_ast(t_token **list, t_env **env_list)
{
	ft_make_bigops(list);
	ft_pipe_nodes(list);
	ft_leaf_nodes(list);
	ft_hdocontree(list, env_list);
	ft_exe_tree(*list, *env_list);
}
