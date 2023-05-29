/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 05:36:15 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/22 14:28:35 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_env	*ft_lstnew(char *key , char *value)
{
	t_env	*new_node;

	new_node = ft_calloc(1, sizeof(t_env));
	if (new_node == NULL)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
