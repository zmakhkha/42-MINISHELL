/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asthdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:05:01 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/26 01:13:32 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// if type == 0 we should expand else no need to
char	*ft_get_path(char *del, int type, t_env **env_list)
{
	int		a;
	char	*tmp;
	char	*path;

	a = -5;
	path = NULL;
	a = fork();
	if (a == 0)
	{
		tmp = ft_heredoc(del);
		path = ft_hdoc_tofd(tmp, type, *env_list);
		exit(0);
	}
	else
	{
		ft_signal_ignore();
		waitpid(-1, &g_status, 0);
		ft_signal_main();
		return (ft_strdup(path));
		// free(tmp);
	}
	return (NULL);
}

void	ft_hdoc_to_file(t_token **list, t_env **env_list)
{
	char	*tmp;

	tmp = NULL;
	if (list && (*list) && (*list)->type == HDOC)
	{
		tmp = ft_strtrim((*list)->str, " \t");
		free((*list)->str);
		if (ft_strchr(tmp, '\'') || ft_strchr(tmp, '\"'))
		{
			tmp = ft_exp1(tmp);
			(*list)->str = ft_get_path(tmp, 0, env_list);
		}
		else
			(*list)->str = ft_get_path(tmp, 1, env_list);
		free(tmp);
		(*list)->type = RE_IN;
	}
}

void	ft_hdocontree(t_token **list, t_env **env_list)
{
	t_token	*lst;

	lst = *list;
	if (list && *list)
	{
		ft_hdocontree(&lst->left, env_list);
		if (lst->type == HDOC)
			ft_hdoc_to_file(&lst, env_list);
		ft_hdocontree(&lst->right, env_list);
	}
}
