/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:36:10 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/01 15:55:29 by zmakhkha         ###   ########.fr       */
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
	if (lst)
	{
		if (ft_loperators(lst) || ft_loperators(ft_getlast(lst)) \
		|| ft_getlast(lst)->type == HDOC)
			g_glob.g_status = ERR;
		while (lst && lst->prev)
		{
			if (ft_isforbidden(lst) == ERR || lst->type == AMP)
				g_glob.g_status = ERR;
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
		g_glob.g_status = ERR;
}
