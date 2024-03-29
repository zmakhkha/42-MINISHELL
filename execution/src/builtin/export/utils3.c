/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:09:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/06 17:46:35 by zmakhkha         ###   ########.fr       */
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
		g_glob.g_exp = 1;
		ft_free_2dstr(tmp);
		return ;
	}
	if (tmp && tmp[0] && tmp[1] && ft_strlen(tmp[1]))
	{
		change_env(tmp[0], tmp[1], &env);
	}
	else if (!ft_strcmp(tmp[1], ""))
		ft_with_quotes(lst, env);
	ft_free_2dstr(tmp);
		g_glob.g_exp = 0;
}

void	ft_detect_one(t_token *lst, t_env *env, int i, int mode)
{
	if (!mode)
	{
		if (i == 0)
			printf("minishell: export: `%s': not a valid identifier\n", \
		lst->str);
		else
			ft_app_exp(lst, env);
	}
}

int	ft_detect(t_token *lst, t_env *env)
{
	int	i;

	i = -1;
	if (lst && lst->str)
	{
		while (lst->str && lst->str[++i])
		{
			if (lst->str[i] == '+' && (i == (int)ft_strlen(lst->str) - 1))
				return \
	(printf("minishell: export: `%s': not a valid identifier\n", lst->str), 1);
			else if (lst->str[i] == '+' && lst->str[i + 1] \
			&& lst->str[i + 1] == '=')
				return (ft_detect_one(lst, env, i, 0), 0);
			else if (lst->str[i] == '=')
			{
				if (i == 0)
					return (printf \
		("minishell: export: `%s': not a valid identifier\n", lst->str), 1);
				else
					ft_rep_exp(lst, env);
				return (g_glob.g_exp);
			}
		}
	}
	return (g_glob.g_exp);
}

// will get a trimmed key=value || key+=vaue
void	ft_parse_export(t_token *lst, t_env *env)
{
	if (lst && lst->str && (ft_strchr(lst->str, '+') || ft_strchr(lst->str,
				'=')))
	{
		while (lst)
		{
			g_glob.g_exp = ft_detect(lst, env);
			lst = lst->prev;
		}
	}
	else
		ft_no_qoute(lst, env);
}

t_env	*ft_copyenv(t_env *env)
{
	t_env	*res;

	res = NULL;
	while (env)
	{
		add_env_node(env->key, env->value, &res);
		env = env->next;
	}
	return (res);
}

// void	ft_print_exp(t_env *env)
// {
// 	declare_env(&env);
// }
