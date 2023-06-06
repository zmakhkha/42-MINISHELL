/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:58:22 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/06 12:10:32 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"


t_env	*new_env_node(char *key, char *value)
{
	t_env	*new_lst;

	new_lst = (t_env *)malloc(sizeof(t_env));
	if (!new_lst)
		return (NULL);
	new_lst->key = key;
	new_lst->value = value;
	new_lst->next = NULL;
	return (new_lst);
}

void	add_env_node(char *key, char *value, t_env **env_list)
{
	t_env	*new;

	new = new_env_node(key, value);
	if (!new)
	{
		exit(1);
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
		ft_error("Path env is not set", "");
		return (NULL);
	}
	i = 0;
	tmp = NULL;
	env_list = NULL;
	while (env[i])
	{
		tmp = ft_split(env[i], '=');
		key = tmp[0];
		value = tmp[1];
		add_env_node(key, value, &env_list);
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
