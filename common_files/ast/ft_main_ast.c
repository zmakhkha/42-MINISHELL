/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:58:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/28 17:59:32 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_main_ast(t_token **list)
{
	printf("\n The  tree stage \n");
	ft_make_bigops(list);
	ft_pipe_nodes(list);
	ft_leaf_nodes(list);
	ft_print_tree(*list);
}
