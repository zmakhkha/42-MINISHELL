/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asthdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:05:01 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/04 20:35:11 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"
// if type == 0 we should expand else no need to
char	*ft_get_path(char *del, int type, t_env **env_list)
{
	int		a;
	char	*tmp;
	char	*path;
	int		p[2];

	if (pipe(p) == -1)
		perror("minishell : ");
	a = -5;
	path = ft_calloc(1000000, sizeof(char ));
	tmp = NULL;
	a = fork();
	signal(SIGINT, SIG_IGN);
	rl_catch_signals = 1;
	if (!a)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
		tmp = ft_heredoc(del);
		path = ft_hdoc_tofd(tmp, type, *env_list);
		close(p[0]);
		write(p[1], tmp, ft_strlen(tmp));
		close(p[1]);
		exit(0);
	}
	rl_catch_signals = 0;
	waitpid(a, NULL, 0);
	ft_signal_main();
	close (p[1]);
    read(p[0], tmp, 10000);
	puts(path);
	return (path);
}

void	ft_hdoc_to_file(t_token **list, t_env **env_list)
{
	char	*tmp;

	tmp = NULL;
	if (list && (*list) && (*list)->type == HDOC)
	{
		tmp = ft_strtrim((*list)->str, " \t");
		free((*list)->str);
		(*list)->str = NULL;
		if (ft_strchr(tmp, '\'') || ft_strchr(tmp, '\"'))
		{
			free(tmp);
			tmp = ft_strtrim(tmp, " \'\"");
			(*list)->str = ft_get_path(tmp, 0, env_list);
		}
		else
			(*list)->str = ft_get_path(tmp, 1, env_list);
		(*list)->type = RE_IN;
		free(tmp);
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
