/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/20 19:40:05 by zmakhkha         ###   ########.fr       */
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
	tmp->prev = NULL;
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
	}
}

void	ft_free_token(t_token **t)
{
	t_token	*tmp;

	if (t && *t)
	{
		if ((*t)-> prev == NULL)
		{
			if ((*t)->str)
				free((*t)->str);
			free (*t);
		}
		else
		{
			while ((*t)->prev)
			{
				tmp = *t;
				(*t) = (*t)->prev;
				if (tmp->str)
					free(tmp->str);
				free (tmp);
			}
			if ((*t)->str)
				free((*t)->str);
			free ((*t));
		}
	}
}

void	ft_delete_next_token(t_token **t)
{
	t_token	*tmp;
	t_token	*rep;

	if (t && *t && (*t)->prev)
	{
		tmp = *t;
		rep = tmp->prev;
		tmp->prev = rep->prev;
		free (rep->str);
		free (rep);
	}
}
