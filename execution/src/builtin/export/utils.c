/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:21:50 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/01 22:56:16 by zmakhkha         ###   ########.fr       */
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
			s_tmp = ft_join_free(lst->str, lst->prev->str);
			free(lst->str);
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

#define APP -10
#define REP -20

void	ft_with_quotes(t_token *lst, t_env *env)
{
	char	*key;

	key = ft_substr(lst->str, 0, ft_strlen(lst->str) - 1);
	if (!ft_isvalidkey(key))
	{
		printf("minishell export `%s' : not a valid identifier\n", key);
		return ;
	}
	if (!get_value(key, env))
		change_env(key, ft_strdup("with"), &env);
}

void	ft_no_qoute(t_token *lst, t_env *env)
{
	char	*key;

	key = ft_substr(lst->str, 0, ft_strlen(lst->str));
	if (!ft_isvalidkey(key))
	{
		printf("minishell export `%s' : not a valid identifier\n", key);
		return ;
	}
	if (!get_value(key, env))
		change_env(key, ft_strdup("No"), &env);
}

void	ft_app_exp(t_token *lst, t_env *env)
{
	char	**tmp;
	char	*s_tmp;
	char	*key;
	char	*t_key;

	tmp = NULL;
	tmp = ft_devide(lst->str, '=');
	key = ft_substr(tmp[0], 0, ft_strlen(tmp[0]) - 1);
	if (!ft_isvalidkey(key))
	{
		printf("minishell export `%s' : not a valid identifier\n", key);
		return ;
	}
	if (tmp && tmp[0] && tmp[1] && ft_strlen(tmp[1]))
	{
		t_key = get_value(key, env);
		if (!ft_strcmp(t_key, "with") || !ft_strcmp(t_key, "No"))
		{
			free(t_key);
			t_key = NULL;
		}
		s_tmp = ft_join_free(t_key, ft_strtrim(tmp[1], "\"\'"));
		change_env(key, ft_strtrim(s_tmp, "\'\""), &env);
	}
	else if (!ft_strlen(tmp[1]))
	{
		lst->str = key;
		ft_with_quotes(lst, env);
	}
}

void	ft_rep_exp(t_token *lst, t_env *env)
{
	char	**tmp;
	char	*key;

	tmp = ft_devide(lst->str, '=');
	key = tmp[0];
	if (!ft_isvalidkey(key))
	{
		printf("minishell export `%s' : not a valid identifier\n", key);
		return ;
	}
	if (tmp && tmp[0] && tmp[1] && ft_strlen(tmp[1]))
		change_env(tmp[0], ft_strtrim(tmp[1], "\'\""), &env);
	else if (!ft_strcmp(tmp[1], ""))
		ft_with_quotes(lst, env);
}

void	ft_detect(t_token *lst, t_env *env)
{
	int	i;

	i = -1;
	if (lst && lst->str)
	{
		while (lst->str && lst->str[++i])
		{
			if (lst->str[i] == '+' && lst->str[i + 1] && lst->str[i + 1] == '=')
			{
				if (i == 0)
					printf("minishell: export: `%s': not a valid identifier\n",
						lst->str);
				else
					ft_app_exp(lst, env);
				return ;
			}
			else if (lst->str[i] == '=')
			{
				if (i == 0)
					printf("minishell: export: `%s': not a valid identifier\n",
						lst->str);
				else
					ft_rep_exp(lst, env);
				return ;
			}
		}
	}
}

// will get a trimmed key=value || key+=vaue
void	ft_parse_export(t_token *lst, t_env *env)
{
	if (lst && lst->str && (ft_strchr(lst->str, '+') || ft_strchr(lst->str,
				'=')))
	{
		while (lst)
		{
			ft_detect(lst, env);
			lst = lst->prev;
		}
	}
	else
		ft_no_qoute(lst, env);
}

void	ft_print_exp(t_env *env)
{
	while (env)
	{
		printf("declare -x ");
		printf("%s", env->key);
		if (!ft_strcmp(env->value, "No"))
		{
			printf("\n");
			env = env->next;
			continue ;
		}
		else if (!ft_strcmp(env->value, "with") || !ft_strcmp(env->value, ""))
			printf("=\"\"\n");
		else
			printf("=\"%s\"\n", env->value);
		env = env->next;
	}
}

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
	// ft_makekey_value(lst, env);
}