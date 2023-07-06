/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 05:25:46 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/06 18:55:42 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

void	free_env_node(t_env *node)
{
	if (node == NULL)
		return ;
	if (node->key != NULL)
	{
		free(node->key);
		node->key = NULL;
	}
	if (node->value != NULL)
	{
		free(node->value);
		node->key = NULL;
	}
	free(node);
	node = NULL;
}

void	unset_env(const char *key, t_env **env_list)
{
	t_env	*current;

	if (env_list && *env_list)
	{
		if (!ft_strcmp(key, (*env_list)->key))
		{
			current = (*env_list);
			*env_list = (*env_list)->next;
			if (current->key)
				free(current->key);
			current->key = NULL;
			if (current->value)
				free(current->value);
			current->value = NULL;
			current->next = NULL;
			current = NULL;
		}
		else
			unset_env(key, &(*env_list)->next);
	}
}

int	execute_unset(char **list, t_env **env_list)
{
	int	i;
	int	valid;

	valid = 0;
	i = 1;
	if (!list[0])
		return (EXIT_SUCCESS);
	while (list[i])
	{
		valid = ft_isvalidkey(list[i]);
		if (valid)
			unset_env(list[i], env_list);
		i++;
	}
	return (EXIT_FAILURE);
}
