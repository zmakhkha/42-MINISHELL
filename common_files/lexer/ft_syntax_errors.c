/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:36:10 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/17 16:50:22 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_loperators(t_token *lst)
{
	return (lst->type == PIPE || lst->type == AMP || lst->type == AND || \
	lst->type == OR);
}

int	ft_isforbidden(t_token *lst)
{
	int	ret;

	ret = SUCC;
	if (lst && lst->prev)
		ret = ((ft_loperators(lst) && ft_loperators(lst->prev)) \
		|| (ft_loperators(lst) && (lst->prev->type == SPACE) && \
		ft_loperators(lst->prev->prev)));
	return (ret);
}

int	ft_check_op(t_token *lst)
{
	t_token	*tail;
	int		ret;

	ret = SUCC;
	tail = NULL;
	if (lst)
	{
		if (ft_loperators(lst) || ft_loperators(ft_getlast(lst)) \
		|| ft_getlast(lst)->type == HDOC)
			return (ERR);
		while (lst && lst->prev)
		{
			if (ft_isforbidden(lst) == ERR)
				return (ERR);
			lst = lst->prev;
		}
	}
	return (ret);
}
