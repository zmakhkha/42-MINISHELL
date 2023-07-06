/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asthdoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:05:01 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/06 14:10:07 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	ft_handle_pipe(char *path, int *p)
{
	close(p[0]);
	write(p[1], path, ft_strlen(path));
	close(p[1]);
	exit(0);
}

// if type == 0 we should expand else no need to
char	*ft_get_path(char *del, int type, t_env **env_list)
{
	int		a;
	char	*tmp;
	char	*path;
	int		p[2];

	if (pipe(p) == -1)
		perror("minishell : ");
	path = ft_calloc(1000000, sizeof(char));
	a = fork();
	signal(SIGINT, SIG_IGN);
	rl_catch_signals = 1;
	if (!a)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
		tmp = ft_heredoc(del);
		path = ft_hdoc_tofd(tmp, type, *env_list);
		ft_handle_pipe(path, p);
	}
	rl_catch_signals = 0;
	waitpid(a, NULL, 0);
	ft_signal_main();
	close(p[1]);
	read(p[0], path, 10000);
	return (path);
}

char	*ft_rmsq_(char *str)
{
	int		i;
	int		len;
	char	c;
	char	*t;

	i = 0;
	len = 0;
	while (str[i] && (str[i] != '\"') && (str[i] != '\''))
		i++;
	if (str[i])
		c = str[i];
	else
		return (str);
	i = -1;
	while (str[++i])
	{
		if (str[i] != c)
			len++;
	}
	t = ft__rmsq2(str, len, c);
	free(str);
	return (t);
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
			tmp = ft_rmsq_(tmp);
			tmp = ft_rmsq_(tmp);
			printf("------->(%s)\n", tmp);
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
