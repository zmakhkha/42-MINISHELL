/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:58:22 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/22 09:04:02 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

t_env	*new_env_node(char *key, char *value)
{
	t_env	*new_lst;

	new_lst = (t_env *)malloc(sizeof(t_env));
	if (!new_lst)
		return (NULL);
	new_lst->key = ft_strdup(key);
	if(value == NULL)
		new_lst->value = ft_strdup("");
	else
		new_lst->value = ft_strdup(value);
	new_lst->next = NULL;
	return (new_lst);
}

void	add_env_node(char *key, char *value, t_env **env_list)
{
	t_env	*new;

	new = new_env_node(key, value);
	if (!new)
	{
		ft_putendl_fd("Failed to allocate memory", ER);
		return;
	}
	ft_lstadd_back(env_list, new);
}

t_env	*set_env(char **env)
{
	t_env	*env_list;
	int		i;
	char	*key;
	char	*value;
	char	**tmp;

	if (env == NULL)
	{
		ft_putendl_fd("minishell: Path env is not set", ER);
		return (NULL);
	}
	i = 0;
	tmp = NULL;
	env_list = NULL;
	while (env[i])
	{
		tmp = ft_split(env[i], '=');
		if (!tmp)
		{
			ft_putendl_fd("Failed to allocate memory", ER);
			return (NULL);
		}
		key = tmp[0];
		value = tmp[1];
		add_env_node(key, value, &env_list);
		ft_free_2dstr(tmp);
		tmp = NULL;
		i++;
	}
	return (env_list);
}

char	*get_value(char *key, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}