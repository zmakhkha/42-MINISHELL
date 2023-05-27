/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:36:10 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/27 17:53:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_loperators(t_token *lst)
{
	return (lst->type == PIPE || lst->type == AMP);
}

int	ft_isbigoperators(t_token *lst)
{
	return (lst->type == AND || lst->type == OR);
}

int	ft_isforbidden(t_token *lst)
{
	int	ret;

	ret = SUCC;
	if (lst && lst->prev && lst->prev->prev)
		ret = ((ft_loperators(lst) && ft_loperators(lst->prev) \
		&& ft_loperators(lst->prev->prev)) \
		|| (ft_loperators(lst) && (lst->prev->type == SPACE) && \
		ft_loperators(lst->prev->prev)));
	return (ret);
}

void	ft_check_op(t_token *lst)
{
	t_token	*tail;
	int		ret;

	ret = SUCC;
	tail = NULL;
	if (lst)
	{
		if (ft_loperators(lst) || ft_loperators(ft_getlast(lst)) \
		|| ft_getlast(lst)->type == HDOC)
			g_status = ERR;
		while (lst && lst->prev)
		{
			if (ft_isforbidden(lst) == ERR || lst->type == AMP)
				g_status = ERR;
			lst = lst->prev;
		}
	}
}

void	ft_operrors(t_token *lst)
{
	t_token	*head;
	t_token	*tail;

	head = ft_getfirst(lst);
	tail = ft_getlast(lst);
	if (ft_loperators(head) || ft_loperators(tail) || ft_isbigoperators(head) \
	|| ft_isbigoperators(tail))
		g_status = ERR;
}

void	ft_succop(t_token *lst)
{
	if (lst && lst->prev)
	{
		ft_succop(lst->prev);
		if ((lst->type == PIPE && ft_isbigoperators(lst->prev)) || \
			(ft_isbigoperators(lst) && lst->prev->type == PIPE))
		{
			g_status = ERR;
			// break ;
		}
		lst = lst->prev;
	}
}

// this is an extreme case redirection -> subshell == error
// we should check that before swapping
void	ft_sub_red(t_token *lst)
{
		if (ft_isredirection(lst) && lst->prev->type == SUBSHELL)
		{
			g_status = ERR;
			puts("3\n");
		}
}

void	ft_syntaxerr(t_token *lst)
{
	if (lst && lst->prev)
	{
		ft_syntaxerr(lst->prev);
		if (lst->type == SUBSHELL && (lst->prev->type == SUBSHELL \
		|| lst->prev->type == WORD))
		{
			g_status = ERR;
			puts("1\n");
		}
		if ((lst->type == SUBSHELL || lst->type == WORD) && \
		lst->prev->type == SUBSHELL)
		{
			g_status = ERR;
			puts("2\n");
		}
		if (lst->type == HDOC && (lst->prev->type == SUBSHELL))
		{
			g_status = ERR;
			puts("3\n");
		}
	}
}

// if we remove the next pointers it double free
void	ft_op_space(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		// ft_op_space(&lst->prev);
		if (lst && ((ft_isredirection(lst)) || lst->type == PIPE \
			|| lst->type == HDOC || lst->type == SUBSHELL || \
			ft_isbigoperators(lst)) && (lst->prev->type == SPACE))
			ft_remove_tok(list, lst->prev);
	lst = lst->prev;
	}
}
