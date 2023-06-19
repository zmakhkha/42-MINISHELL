/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:58:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/19 18:43:24 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// we need to expand just envirennement vars
char	*ft_expandchar(char *str, t_env **env_list)
{
	(void)env_list;
	return(str);
}

// if type == 0 we should expand else no need to
char	*ft_get_path(char *del, int type, t_env **env_list)
{
	int	a;
	char	*tmp;
	char	*path;

	a = -5;
	path = NULL;
	a = fork();
	if (a == 0)
	{
		tmp = ft_heredoc(del);
		path = ft_strdup(ft_hdoc_tofd(tmp));
		if (type)
			path = ft_expandchar(path, env_list);
	}
	else
	{
		waitpid(a, NULL, 0);
	}
	return (path);
}


void	ft_hdoc_to_file(t_token **list, t_env **env_list)
{
	char	*tmp;

	if (list && (*list) && (*list)->type == HDOC)
	{
		tmp = (*list)->str;
		if ((*list)->str[0] != '\'' || (*list)->str[0] != '\'')
		{
			(*list)->str = 	ft_get_path((*list)->str, 1, env_list);
		}
		else
			(*list)->str = 	ft_get_path(ft_strtrim((*list)->str, " "), 0, env_list);
		(*list)->type = RE_IN;
	}
}

void	ft_hdocontree(t_token **list, t_env **env_list)
{
	t_token	*lst;

	if (list && *list)
	{
		lst = *list;
		ft_hdocontree(&lst->left, env_list);
		if (lst->type == HDOC)
			ft_hdoc_to_file(&lst, env_list);
		ft_hdocontree(&lst, env_list);
		ft_hdocontree(&lst->right, env_list);
		
	}
}

void	ft_main_ast(t_token **list, t_env **env_list)
{
	ft_make_bigops(list);
	ft_pipe_nodes(list);
	ft_leaf_nodes(list);
	ft_hdocontree(list, env_list);
	ft_exe_tree(*list, *env_list);
}
