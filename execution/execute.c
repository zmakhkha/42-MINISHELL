/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:55:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 03:29:18 by ayel-fil         ###   ########.fr       */
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

int	ft_execution(t_token *list, t_env **env)
{
	int	status;

	status = g_glob.g_status_exit;
	if (!list)
		return (EXIT_FAILURE);
	if (list->type == PIPE || list->type == AND || list->type == OR \
	|| list->type == Empty)
		status = execute_logical_op(list, *env);
	if (list->type == APPEND || list->type == RE_OUT)
		status = execute_simple(list, status);
	if (list->type == WORD)
		status = execute_word(list, env, status);
	g_glob.g_status_exit = status;
	return (status);
}
