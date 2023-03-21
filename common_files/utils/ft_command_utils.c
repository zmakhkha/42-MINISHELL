/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:50:44 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/21 18:57:39 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_token	*ft_add_comm(char **str)
{
	t_token	*tmp;

	if (!str && !(*str))
		return (NULL);
	tmp = (t_command *) malloc(sizeof(t_command));
	if (!tmp)
		ft_exit("Token allocation failed", 1);
	tmp->str = str;
	tmp->prev = NULL;
	return (tmp);
}

void	ft_comm_addback(t_command **lst, t_command *new)
{
	t_command	*pos;

	if (*lst == NULL)
		*lst = new;
	else
	{
		pos = *lst;
		while (pos -> prev != NULL)
			pos = pos -> prev;
		pos -> prev = new;
	}
}

// void	ft_free_comm(t_command **t)
// {
// 	t_command	*tmp;

// 	if (t && *t)
// 	{
// 		if ((*t)-> prev == NULL)
// 		{
// 			if ((*t)->str)
// 				free((*t)->str);
// 			free (*t);
// 		}
// 		else
// 		{
// 			while ((*t)->prev)
// 			{
// 				tmp = *t;
// 				(*t) = (*t)->prev;
// 				if (tmp->str)
// 					free(tmp->str);
// 				free (tmp);
// 			}
// 			if ((*t)->str)
// 				free((*t)->str);
// 			free ((*t));
// 		}
// 	}
// }