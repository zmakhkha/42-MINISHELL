/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:05:09 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/13 03:52:58 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_env(t_env **env_list)
{
	t_env	*current;

	current = *env_list;
	while (current != NULL)
	{
		ft_putstr_fd(current->key, 1);
		ft_putstr_fd("=", 1);
		if (current->value == NULL)
			ft_putendl_fd("", 1);
		ft_putendl_fd(current->value, 1);
		current = current->next;
	}
	return (0);
}

void	change_env(char *key, char *value, t_env **env_list)
{
	t_env	*tmp;

	tmp = *env_list;
	while (tmp)
	{
		if (ft_strcmp(key, tmp->key) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	// If the key does not exist, create a new node and add it to the list
	add_env_node(key, value, env_list);
}

char	**list_to_array(t_env *env)
{
	int		length;
	int		i;
	char	**array;
	char	*join_str;
	char	*tmp;

	i = 0;
	length = ft_lstsize(env);
	array = ft_calloc(length + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (env != NULL)
	{
		if (env->value == NULL)
			env->value = ft_strdup("");
		join_str = ft_strjoin(env->key, "=");
		tmp = ft_strjoin(join_str, env->value);
		free(join_str);
		array[i] = ft_strdup(tmp);
		free(tmp);
		env = env->next;
		i++;
	}
	return (array);
}
