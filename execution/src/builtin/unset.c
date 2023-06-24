/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 05:25:46 by ayel-fil          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/24 10:44:02 by ayel-fil         ###   ########.fr       */
=======
/*   Updated: 2023/06/22 10:44:31 by zmakhkha         ###   ########.fr       */
>>>>>>> parent of ab0bb26... Merge pull request #21 from zmakhkha/exe
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
	t_env	*prev;

	current = *env_list;
	prev = NULL;
	while (current != NULL)
	{
		if (!ft_strcmp(current->key, key))
		{
			if (prev == NULL)
				*env_list = current->next;
			else
				prev->next = current->next;
			free_env_node(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
int	execute_unset(char **list, t_env **env_list)
{
	int	i;

	i = 1;
	if (!list[0])
		return (EXIT_SUCCESS);
	while (list[i])
		unset_env(list[i++], env_list);
	return (EXIT_FAILURE);
}
