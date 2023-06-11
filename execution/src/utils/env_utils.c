/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:05:09 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/11 15:50:47 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_env(t_env **env_list)
{
	t_env	*current;

	current = *env_list;
	while (current != NULL)
	{
		ft_putstr_fd(current->key,1);
		ft_putstr_fd("=",1);
		if(current->value == NULL)
			ft_putendl_fd("",1);
		ft_putendl_fd(current->value,1);
		current = current->next;
	}
	return (0);
}

void	change_env(char *key, char *value, t_env *env)
{
	while (env)
	{
		if (!ft_strcmp(key, env->key))
		{
			free(env->value);
			env->value = ft_strdup(value);
			return ;
		}
		env = env->next;
	}
	add_env_node(key, value, &env);
}

 char	**list_to_array(t_env *env)
{
	int length;
	int i;
	char **array;

	i = 0;
	length = ft_lstsize(env);
	array = ft_calloc(length + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (env != NULL)
	{
		if(env->value == NULL)
			env->value = ft_strdup("");
		char *join_str = ft_strjoin(env->key, "=");
		char *tmp = ft_strjoin(join_str, env->value);
		free(join_str);
		array[i] = ft_strdup(tmp);
		free(tmp);
		env = env->next;
		i++;
	}

	return (array);
} 
