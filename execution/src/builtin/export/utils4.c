/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:33:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/03 13:32:07 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header.h"

void	ft_handle_one(char *s, t_env **env)
{
	t_token	*lst;

	(void)env;
	s = ft_strtrim(s, " ");
	lst = ft_strtok(s);
	ft_mergewords(&lst);
	ft_mergewordspace(&lst);
	ft_merge_num_word(&lst);
	ft_mergeword_num(&lst);
	ft_rm_space_(&lst);
	ft_parse_export(lst, *env);
	ft_free_token(&lst);
	free(s);
}

void	ft__app_exp(char *key, char *t_key, t_env *env, char **tmp)
{
	char	*s_tmp;

	t_key = get_value(key, env);
	if (!ft_strcmp(t_key, "with"))
	{
		t_key = ft_strtrim(tmp[1], "\'\"");
		puts(t_key);
		change_env(key, t_key, &env);
	}
	else
	{		
		puts("ana joujoun");
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
