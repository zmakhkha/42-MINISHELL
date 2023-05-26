/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:18:56 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/26 15:23:52 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_subshells(t_token *lst)
{
	int	i;

	i = SUCC;
	if (lst)
	{
		while (lst && lst->prev)
		{
			if (((lst->type == SUBSHELL) && ((lst->prev->type \
			== SUBSHELL) || (lst->prev->type == WORD))) || \
			((lst->type == WORD) && ((lst->prev->type == SUBSHELL) \
			|| (lst->prev->type == WORD))))
			{
				i = ERR;
				ft_print("Parse Error near ( or ) !!\n");
			}
			lst = lst->prev;
		}
	}
	return (i);
}

// Detects PIPE and AND operators
void	ft_detect_op(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (lst->type == PIPE) && (lst->prev->type == PIPE))
		{
			lst->type = OR;
			free(lst->str);
			lst->str = ft_strdup("||");
			ft_remove_tok(list, lst->prev);
		}
		else if (lst && (lst->type == AMP) && (lst->prev->type == AMP))
		{
			lst->type = AND;
			free(lst->str);
			lst->str = ft_strdup("&&");
			ft_remove_tok(list, lst->prev);
		}
		lst = lst->prev;
	}
}
