/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:58:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/06 15:50:18 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_main_ast(t_token **list,t_env **env_list)
{
	// printf("\n The  tree stage \n");
	ft_make_bigops(list);
	ft_pipe_nodes(list);
	ft_leaf_nodes(list);
	ft_exe_tree(*list,*env_list);
}
