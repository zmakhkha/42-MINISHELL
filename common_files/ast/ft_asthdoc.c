/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asthdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:05:01 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/26 03:47:04 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_heredoc_handler()
{
	struct sigaction	sa;

	sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);
}

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
		ft_heredoc_handler();
		tmp = ft_heredoc(del);
		path = ft_hdoc_tofd(tmp, type, *env_list);
		return ft_strdup(path);
		exit(0);
	}
	else if (a > 0)
	{
		ft_signal_ignore();
		waitpid(-1, &g_status, 0);
		ft_signal_main();
		return ft_strdup(path);
	}
	else
	{
		perror("fork");
		exit(1);
	}
		return ft_strdup(path);
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
