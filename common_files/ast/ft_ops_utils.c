/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:25:11 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/28 17:24:25 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// check if there is a big operator in list or no
int	ft_isthere_bop(t_token *lst)
{
	if (lst)
	{	
		lst = ft_getfirst(lst);
		while (lst)
		{
			if (ft_isbigoperators(lst))
				return (1);
			lst = lst->prev;
		}
	}
	return (0);
}

void	ft_make_bigops(t_token **list)
{
	t_token	*tail;

	if (list && ft_isthere_bop(*list))
	{
		tail = ft_getlast(*list);
		while (tail && !ft_isbigoperators(tail))
			tail = tail->next;
		if (tail->prev)
			tail->prev->next = NULL;
		tail->right = tail->prev;
		if (tail->next)
			tail->next->prev = NULL;
		tail->left = tail->next;
		tail->prev = NULL;
		tail->next = NULL;
		ft_make_bigops(&(tail->left));
		*list = tail;
	}
}

// check if there is a pipe operator in list or no
int	ft_isthere_pipe(t_token *lst)
{
	if (lst)
	{
		ft_isthere_pipe(lst->left);
		lst = ft_getlast(lst);
		while (lst)
		{
			if (lst->type == PIPE)
				return (1);
			lst = lst->next;
		}
	}
	return (0);
}

t_token	*ft_make_pipes(t_token **list)
{
	t_token	*tail;

	tail = NULL;
	if (list && *list && ft_isthere_pipe(*list))
	{
		tail = ft_getlast(*list);
		while (tail && tail->type != PIPE)
			tail = tail->next;
		if (tail->prev)
		{
			tail->prev->next = NULL;
			tail->right = tail->prev;
		}
		if (tail->next)
		{
			tail->next->prev = NULL;
			tail->left = tail->next;
		}
		tail->prev = NULL;
		tail->next = NULL;
		ft_make_pipes(&(tail->left));
		*list = tail;
	}
	return (*list);
}

void	ft_pipe_nodes(t_token **list)
{
	if (list && *list)
	{
		ft_pipe_nodes(&(*list)->left);
		ft_pipe_nodes(&(*list)->right);
		if ((*list)->left)
		{
			if (ft_isthere_pipe((*list)->left) && \
			ft_lstlen((*list)->right) > 1)
				(*list)->left = ft_make_pipes(&(*list)->left);
		}
		if ((*list)->right)
		{
			if (ft_isthere_pipe((*list)->right) && \
			ft_lstlen((*list)->right) > 1)
				(*list)->right = ft_make_pipes(&(*list)->right);
		}
		if (ft_isthere_pipe(*list) && ft_lstlen((*list)) > 1)
			*list = ft_make_pipes(list);
	}
}
