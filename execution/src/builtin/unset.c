/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 05:25:46 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/13 09:29:22 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

void	free_env_node(t_env *node)
{
	if (node == NULL)
		return ;
	if (node->key)
		free(node->key);
	if (node->key)
		free(node->value);
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
		if (ft_strcmp(current->key, key) == 0)
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
	if (!list[1])
	{
		ft_putendl_fd("unset: invalid syntax", 2);
		return (1);
	}
	printf("test - >(%d)\n", ft_lstsize(*env_list));
	unset_env((*env_list)->key, env_list);
	printf("test - >(%d)\n", ft_lstsize(*env_list));
	return (0);
}
