/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:12:49 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/18 18:41:06 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// if the first or the last object is an operator we raise error : done
int	ft_check_operators(t_token *lst)
{
	t_token	*tmp;

	if (lst)
	{
		tmp = ft_getlast(lst);
		if (!(lst->index) && ((lst->type == OR) || (lst->type == AND) \
		|| (lst->type == PIPE)))
			ft_print("Parse Error near operator !!\n");
		else if ((tmp->type == OR) || (tmp->type == AND) || \
		(tmp->type == PIPE) || (tmp->type == APPEND) \
		|| (tmp->type == RE_IN) || (tmp->type == RE_OUT))
			ft_print("Parse Error near operator !!\n");
	}
	return (1);
}

int	if_valid_re_floower(t_token *node)
{
	if (node && node->prev)
		return (node->prev->type == WORD || node->prev->type == SQ_COMM \
		|| node->prev->type == DQ_COMM);
	return (0);
}

int	if_isredirection(t_token *node)
{
	return ((node->type == RE_IN) || (node->type == RE_OUT) \
	|| (node->type == APPEND));
}

// if the redirection are correct
int	ft_check_redirections(t_token *lst)
{
	int	i;

	i = SUCC;
	if (lst && lst->prev)
	{
		while (lst && lst->prev && !if_isredirection(lst))
			lst = lst->prev;
		if (if_isredirection(lst) && !if_valid_re_floower(lst))
			i = ERR;
		lst = lst->prev;
	}
	if (i == ERR)
	{
		printf("redirection Error !!\n");
		return (ERR);
	}
	else
		return (SUCC);
}
