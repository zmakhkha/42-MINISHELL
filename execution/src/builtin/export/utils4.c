/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:33:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/06 15:57:06 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header.h"

char	*ft_twootoone_(char **str)
{
	int		i;
	char	*res;

	i = -1;
	res = NULL;
	while (str[++i])
	{
		res = ft_join_free(res, str[i]);
	}
	i = -1;
	return (res);
}

void	ft_handle_one(char *s, t_env **env)
{
	t_token	*lst;
	t_token	*t;
	char	**tm;
	char	*tmp;

	t = NULL;
	s = ft_strtrim(s, " ");
	lst = ft_strtok(s);
	t = lst;
	ft_mergewords(&lst);
	ft_merge_num_word(&lst);
	ft_mergeword_num(&lst);
	ft_rm_space_(&lst);
	while (lst)
	{
		tmp = lst->str;
		tm = ft_main_exp(lst->str, *env, 1);
		lst->str = ft_twootoone_(tm);
		free(tmp);
		free(tm);
		lst = lst->prev;
	}
	ft_parse_export(t, *env);
	ft_free_token(&t);
	free(s);
}

void	ft__app_exp(char *key, char *t_key, t_env *env, char **tmp)
{
	char	*s_tmp;

	t_key = get_value(key, env);
	if (t_key && !ft_strcmp(t_key, "with"))
	{
		t_key = ft_strtrim(tmp[1], "\'\"");
		puts(t_key);
		change_env(key, t_key, &env);
	}
	else
	{		
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
		g_glob.g_exp = 0;
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
		g_glob.g_exp = 1;
		free(key);
		ft_free_2dstr(tmp);
		return ;
	}
	if (tmp && tmp[0] && tmp[1] && ft_strlen(tmp[1]))
		ft__app_exp(key, t_key, env, tmp);
	else if (!ft_strlen(tmp[1]))
	{
		free(lst->str);
		lst->str = key;
		ft_with_quotes(lst, env);
	}
	ft_free_2dstr(tmp);
}
