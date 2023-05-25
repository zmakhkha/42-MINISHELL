/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:08:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/25 23:29:51 by zmakhkha         ###   ########.fr       */
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

void	ft_delete_prev_token(t_token **t)
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

void	ft_delete_next_token(t_token **t)
{
	t_token	*tmp;
	t_token	*rep;

	if (t && *t && (*t)->next)
	{
		tmp = *t;
		rep = tmp->next;
		tmp->next = rep->next;
		free (rep->str);
		free (rep);
	}
}

void	ft_remove_tok(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	lst = *list;
	tmp = NULL;
	if (lst)
	{
		if (!lst->prev && !lst->next)
		{
			free (lst->str);
			lst->str = NULL;
			free (lst);
			lst = NULL;
		}
		else if (!lst->prev)
		{
			lst->next->prev = NULL;
			free (lst->str);
			lst->str = NULL;
			free (lst);
			lst = NULL;
		}
		else if (!lst->next)
		{
			free (lst->str);
			lst->prev->next = NULL;
			free (lst);
			lst = NULL;
		}
		else
		{
			tmp = lst;
			lst->next->prev = lst->prev;
			lst->prev->next = lst->next;
			free(tmp->str);
			tmp->str = NULL;
			free(tmp);
			tmp = NULL;
		}
	}
}

void	ft_swap(t_token *lst)
{
	t_token	*t_next;
	t_token	*t_prev;
	t_token	*tmp;

	t_prev = lst->prev;
	t_next = lst->next;
	tmp = t_prev->prev;
	if (!t_prev && !t_next);
	else if (lst && t_prev)
	{
		if (t_next)
			t_next->prev = lst->prev;
		lst->prev= t_prev->prev;
		t_prev->next = t_next;
		t_prev->prev = lst;
		lst->next = t_prev;
		if (tmp)
			tmp->next = lst;
	}
}
