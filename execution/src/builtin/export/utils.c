/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:21:50 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/06 15:58:28 by zmakhkha         ###   ########.fr       */
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
		printf("minishell export `%s' : not a valid identifier\n", key);
		g_glob.g_exp = 1;
		free(key);
		return ;
	}
	a = get_value(key, env);
	if (!a || !ft_strcmp(a, "No"))
		change_env(key, "with", &env);
	free(key);
	g_glob.g_exp = 0;
}

void	ft_no_qoute(t_token *lst, t_env *env)
{
	char	*key;

	key = ft_substr(lst->str, 0, ft_strlen(lst->str));
	if (!ft_isvalidkey(key))
	{
		printf("minishell export `%s' : not a valid identifier\n", key);
		g_glob.g_exp = 1;
		free(key);
		return ;
	}
	if (!get_value(key, env))
		change_env(key, "No", &env);
	free(key);
	g_glob.g_exp = 0;
}
