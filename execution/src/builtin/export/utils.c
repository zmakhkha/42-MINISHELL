/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:21:50 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 23:25:57 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header.h"

void	ft_merge_num_word(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (lst->type == DIGITE) && (lst->prev->type == WORD))
		{
			s_tmp = ft_join_free(lst->str, ft_strdup(lst->prev->str));
			lst->str = s_tmp;
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
}

void	ft_format_print(t_env *env)
{
	while (env)
	{
		printf("declare -x ");
		if (!ft_strcmp(env->value, "-1"))
			printf("%s=\n", env->key);
		else
			printf("%s=\"%s\"\n", env->key, env->value);
		env = env->next;
	}
}

void	ft_with_quotes(t_token *lst, t_env *env)
{
	char	*key;
	char	*a;
	int		i;

	i = 0;
	while (lst->str[i] && lst->str[i] != '=')
		i++;
	key = ft_substr(lst->str, 0, i);
	if (!ft_isvalidkey(key))
	{
		printf("minishell export `%s' : not a valid identifier3\n", key);
		free(key);
		return ;
	}
	a = get_value(key, env);
	if (!a || !ft_strcmp(a, "No"))
		change_env(key, "with", &env);
	free(key);
}

void	ft_no_qoute(t_token *lst, t_env *env)
{
	char	*key;

	key = ft_substr(lst->str, 0, ft_strlen(lst->str));
	if (!ft_isvalidkey(key))
	{
		printf("minishell export `%s' : not a valid identifier2\n", key);
		free(key);
		return ;
	}
	if (!get_value(key, env))
		change_env(key, "No", &env);
	free(key);
}

void	ft__app_exp(char *key, char *t_key, t_env *env, char **tmp)
{
	char	*s_tmp;

	t_key = get_value(key, env);
	s_tmp = ft_strtrim(tmp[1], "\"\'");
	s_tmp = ft_join_free(ft_strdup(t_key), s_tmp);
	t_key = ft_strtrim(s_tmp, "\'\"");
	change_env(key, t_key, &env);
	free(s_tmp);
	s_tmp = NULL;
	free(key);
	key = NULL;
	free(t_key);
	t_key = NULL;
}

void	ft_app_exp(t_token *lst, t_env *env)
{
	char	**tmp;
	char	*key;
	char	*t_key;

	tmp = NULL;
	t_key = NULL;
	tmp = ft_devide(lst->str, '=');
	key = ft_substr(tmp[0], 0, ft_strlen(tmp[0]) - 1);
	if (!ft_isvalidkey(key))
	{
		printf("minishell export `%s' : not a valid identifier1\n", key);
		free(key);
		ft_free_2dstr(tmp);
		return ;
	}
	if (tmp && tmp[0] && tmp[1] && ft_strlen(tmp[1]))
		ft__app_exp(key, t_key, env, tmp);
	else if (!ft_strlen(tmp[1]))
	{
		lst->str = key;
		ft_with_quotes(lst, env);
	}
	ft_free_2dstr(tmp);
}
