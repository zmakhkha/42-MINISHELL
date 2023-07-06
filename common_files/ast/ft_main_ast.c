/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:58:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/25 17:17:51 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_printini(t_token **list )
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
void	print_dot(t_token **list, int i, int *count, FILE *p)
{
	int	node_id;

	if (list == 0x0 || !(*list))
		return ;
	node_id = ++(*count);
	fprintf(p, "  node%d [label=\"%s\"];\n", node_id, (*list)->str);
	if (i != -666)
		fprintf(p, "  node%d -> node%d;\n", i, node_id);
	print_dot(&((*list)->left), node_id, count, p);
	print_dot(&((*list)->right), node_id, count, p);
}

void	print_tree_dot(t_token **list)
{
	int		count;
	FILE	*p;

	p = fopen("treegraph.dot", "w");
	fprintf(p, "/*\n%s\n*/\n", "<baba>");
	fprintf(p, "digraph {\n");
	count = 0;
	print_dot(list, -666, &count, p);
	fprintf(p, "}\n");
	fflush(p);
	fclose(p);
}


void	ft_main_ast(t_token **list, t_env **env_list)
{
	ft_make_bigops(list);
	ft_pipe_nodes(list);
	ft_leaf_nodes(list);
	ft_subtotree(list);
	print_tree_dot(list);
	// ft_printini(list);
	ft_hdocontree(list, env_list);
	
	ft_exe_tree(*list, *env_list);
	
}
