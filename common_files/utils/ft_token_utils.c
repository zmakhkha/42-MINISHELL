/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/27 18:19:48 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_token	*ft_add_token(char *str, int type)
{
	t_token	*tmp;

	if (!str)
		return (NULL);
	tmp = (t_token *) malloc(sizeof(t_token));
	if (!tmp)
		ft_exit("Token allocation failed", 1);
	tmp->str = str;
	tmp->type = type;
	tmp->fd = -1;
	tmp->prev = NULL;
	tmp->next = NULL;
	tmp->left = NULL;
	tmp->right = NULL;
	return (tmp);
}

t_token	*ft_getlast(t_token *lst)
{
	t_token	*tmp;

	tmp = NULL;
	if (lst)
	{
		tmp = lst;
		while (tmp->prev)
			tmp = tmp->prev;
	}
	return (tmp);
}

t_token	*ft_getfirst(t_token *lst)
{
	t_token	*tmp;

	tmp = NULL;
	if (lst)
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
	}
	return (tmp);
}

void	ft_token_addback(t_token **lst, t_token *new)
{
	t_token	*pos;

	if (*lst == NULL)
		*lst = new;
	else
	{
		pos = *lst;
		while (pos -> prev != NULL)
			pos = pos -> prev;
		pos -> prev = new;
		new -> next = pos;
	}
}

// free all the list from any location
void	ft_free_token(t_token **t)
{
	if (t && *t)
	{
		ft_free_token(&(*t)->prev);
		free((*t)->str);
		(*t)->str = NULL;
		free(*t);
		(*t) = NULL;
	}
}
