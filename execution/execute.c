/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:55:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/06 22:20:22 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define QUOTE -10

void	ft_changetype(t_token **t)
{
	t_token	*tmp;

	tmp = *t;
	while (t && tmp)
	{
		if (ft_strchr(tmp->str, '\''))
			tmp->type = QUOTE;
		tmp = tmp->prev;
	}
}

char	**ft_tokto2dstr(t_token *tok)
{
	char	**res;
	int		i;
	t_token	*tmp;

	tmp = tok;
	i = ft_lstlen(tmp);
	res = NULL;
	tmp = tok;
	if (tmp)
	{
		res = ft_calloc(i + 1, sizeof(char *));
		i = -1;
		while (tok)
		{
			res[++i] = ft_strdup(ft_strtrim(tok->str, " "));
			tok = tok->prev;
		}
	}
	i = 0;
	return (res);
}

void	ft_first_exp(t_token **list)
{
	t_token	*lst;

	lst = ft_getlast(*list);
	while (lst && lst->next)
	{
		if (lst->str && lst->str[0] == '"' && lst->next->type == WORD)
			lst->str = ft_strtrim(lst->str, " \"");
		if (lst->str && lst->str[0] == '\'' && lst->next->type == WORD)
			lst->str = ft_strtrim(lst->str, " '");
		lst = lst->next;
	}
	*list = lst;
}

char	**ft_split_command(char *str)
{
	t_token	*tok;
	char	**res;

	res = NULL;
	tok = ft_strtok(str);
	ft_first_exp(&tok);
	ft_mergewords(&tok);
	ft_rm_space_(&tok);
	res = ft_tokto2dstr(tok);
	return (res);
}

int	execute_simple(t_token *list,int status)
{
	int	fd_in;
	int	fd_out;
	
	fd_in = dup(STDIN_FILENO);
	fd_out = dup(STDOUT_FILENO);
	if (list->type == RE_OUT)
		status = run_re_out(list);
	else if (list->type == APPEND)
		status = run_append(list);
	ft_protect(dup2(fd_in, STDIN_FILENO), "dup2", "dup2 failed");
	ft_protect(dup2(fd_out, STDOUT_FILENO), "dup2", "dup2 failed");
	return(status);
}
int	ft_execution(t_token *list, t_env *env)
{
	char	**splited;
	int		status;

	status = 0;
	splited = NULL;
	if (!list)
		return (EXIT_FAILURE);
	if (list->type == PIPE || list->type == AND || list->type == OR
		|| list->type == Empty)
		status = execute_logical_op(list, env);
	if (list->type == APPEND || list->type == RE_OUT)
		status = execute_simple(list,status);
	if (list->type == WORD)
	{
		splited = ft_main_exp(list->str, env, 0);
		if (!splited)
		{
			ft_perror("\"\"", CNF);
			return (127);
		}
		else if (splited[0] && !ft_strcmp(splited[0], "export"))
			ft_export_it(list, &env);
		if (is_builtin(splited))
			status = execute_builtin(splited, env);
		else
			status = execute_command(splited, env);
		ft_free_2dstr(splited);
	}
	return (status);
}
