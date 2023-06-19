/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_errors2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:11:24 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/19 11:13:14 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_succop(t_token *lst)
{
	if (lst && lst->prev)
	{
		ft_succop(lst->prev);
		if ((lst->type == PIPE && ft_isbigoperators(lst->prev)) || \
			(ft_isbigoperators(lst) && lst->prev->type == PIPE))
		{
			g_status = ERR;
		}
		lst = lst->prev;
	}
}

// this is an extreme case redirection -> subshell == error
// we should check that before swapping
void	ft_sub_red(t_token *lst)
{
	if (lst && ft_isredirection(lst) && lst->prev && lst->prev->type == SUBSHELL)
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
		if (lst && ((ft_isredirection(lst)) || lst->type == PIPE \
			|| lst->type == HDOC || lst->type == SUBSHELL || \
			ft_isbigoperators(lst)) && (lst->prev->type == SPACE))
			ft_remove_tok(list, lst->prev);
	lst = lst->prev;
	}
}
