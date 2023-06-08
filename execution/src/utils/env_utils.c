/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:05:09 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/06 15:29:52 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

void	execute_env(t_env **env_list)
{
	t_env	*current;

	current = *env_list;
	while (current != NULL)
	{
		printf("%s=%s\n", current->key, current->value);
		current = current->next;
	}
}

void	change_env(char *key, char *value, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key))
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	add_env_node(key, value, &env);
}

char	**list_to_array(t_env *env)
{
	char	**array;
	t_env	*current;
	char	*join_str;
	int		i;
	int		lenght;
	
	current = env;
	lenght = ft_lstsize(current);
	array = ft_calloc(sizeof(char *), lenght + 1);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (current != NULL)
	{
		join_str = ft_strjoin(current->key, "=");
		join_str = ft_strjoin(join_str, current->value);
		array[i] = ft_strdup(join_str);
		free(join_str);
		current = current->next;
		i++;
	}
	array[lenght] = NULL;
	return (array);
}
