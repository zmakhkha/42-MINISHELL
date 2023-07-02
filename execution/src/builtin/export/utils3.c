/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:09:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 16:10:40 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header.h"

void	ft_rep_exp(t_token *lst, t_env *env)
{
	char	**tmp;
	char	*key;

	tmp = ft_devide(lst->str, '=');
	key = tmp[0];
	if (!ft_isvalidkey(key))
	{
		printf("minishell export `%s' : not a valid identifier\n", key);
		ft_free_2dstr(tmp);
		return ;
	}
	if (tmp && tmp[0] && tmp[1] && ft_strlen(tmp[1]))
	{
		key = ft_strtrim(tmp[1], "\'\"");
		change_env(tmp[0], key, &env);
		free(key);
	}
	else if (!ft_strcmp(tmp[1], ""))
		ft_with_quotes(lst, env);
	ft_free_2dstr(tmp);
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
	ft_free_token(&lst);
	free(s);
	// ft_makekey_value(lst, env);
}
