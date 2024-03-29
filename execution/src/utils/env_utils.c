/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:05:09 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 06:07:40 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_env(t_env *env_list)
{
	t_env	*current;

	current = env_list;
	while (current && current->key)
	{
		if (ft_strcmp(current->key, "") && ft_strcmp(current->value, "")
			&& ft_strcmp(current->value, "with") && ft_strcmp(current->value,
				"No"))
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
				free(tmp->value);
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

void	print_declaration(const char *key, const char *value)
{
	printf("declare -x %s", key);
	if (!ft_strcmp(value, "No"))
	{
		printf("\n");
		return ;
	}
	else if (!ft_strcmp(value, "with") || !ft_strcmp(value, ""))
		printf("=\"\"\n");
	else
		printf("=\"%s\"\n", value);
}

int	declare_env(t_env **env_list)
{
	t_env	*current;
	char	**sorted;
	int		i;
	char	*key;
	char	*value;

	current = *env_list;
	sorted = list_to_array(current);
	sorted = ft_sort_env(sorted);
	i = 0;
	while (sorted && sorted[i] != NULL)
	{
		parse_arguments(sorted[i], &key, &value);
		print_declaration(key, value);
		free(key);
		key = NULL;
		free(value);
		value = NULL;
		i++;
	}
	ft_free_2dstr(sorted);
	return (0);
}
