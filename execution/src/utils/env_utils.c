/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:05:09 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/26 02:03:58 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_env(t_env *env_list)
{
	t_env	*current;

	current = env_list;
	while (current != NULL)
	{
		if (ft_strcmp(current->key, "") && ft_strcmp(current->value, ""))
		{
			ft_putstr_fd(current->key, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(current->value, 1);
		}
		current = current->next;
	}
	return (0);
}

void	change_env(char *key, char *value, t_env **env_list)
{
	t_env	*tmp;

	if (!value)
		value = ft_strdup("");
	tmp = *env_list;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
		{
			if (ft_strcmp(tmp->value, value))
			{
				tmp->value = NULL;
				tmp->value = ft_strdup(value);
			}
			return ;
		}
		tmp = tmp->next;
	}
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
	array[i] = NULL;
	return (array);
}

// void	ft_format_print(t_env *env)
// {
// 	while(env)
// 	{
// 		printf("declare -x ");
// 		if (!ft_strcmp(env->value, "-1"))
// 			printf("%s=\n", env->key);
// 		else
// 			printf("%s=\"%s\"\n", env->key, env->value);
// 		env = env->next;
// 	}
// }
int	declare_env(t_env **env_list)
{
	t_env	*current;
	char	**sorted;
	char	*key;
	char	*value;
	int		i;

	current = *env_list;
	sorted = ft_sort_env(list_to_array(current));
	i = 0;
	while (sorted[i] != NULL)
	{
		parse_arguments(sorted[i], &key, &value);
		printf("declare -x ");
		printf("%s=\"", key);
		// if (value == NULL)
			// printf("\"\n");
		if(ft_strcmp(value, "-1"))
			printf("%s\"\n", value);
		i++;
	}
	return (0);
}

void	free_env(t_env *env_list)
{
	t_env	*current;
	t_env	*next_node;

	current = env_list;
	while (current != NULL)
	{
		next_node = current->next;
		free(current->key);
		free(current->value);
		current->key = NULL;
		current->value = NULL;
		free(current);
		current = next_node;
	}
}
