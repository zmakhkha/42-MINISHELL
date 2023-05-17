/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opperators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:18:56 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/17 16:50:52 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_operator(t_token *l)
{
	return (l->type == HDOC || l->type == AND || \
	l->type == OR || l->type == PIPE);
}

int	ft_operator2(t_token *l)
{
	return (l->type == RE_IN || l->type == RE_OUT || \
	l->type == APPEND);
}

int	ft_opperators(t_token *lst)
{
	int	i;

	i = SUCC;
	if (lst)
	{
		while (lst && lst->prev && lst->prev->prev)
		{
			if (ft_operator(lst) && lst->prev->type == SPACE && \
			ft_operator(lst->prev->prev))
			{
				i = ERR;
				ft_print("Parse Error near operator 3!!\n");
				break ;
			}
			lst = lst->prev;
		}
	}
	return (i);
}

int	ft__opperators(t_token *lst)
{
	int	i;

	i = SUCC;
	if (lst)
	{
		while (lst && lst->prev && lst->prev->prev)
		{
			if (ft_operator2(lst) && lst->prev->type == SPACE && \
			ft_operator2(lst->prev->prev))
			{
				i = ERR;
				ft_print("Parse Error near operator 3!!\n");
				break ;
			}
			lst = lst->prev;
		}
	}
	return (i);
}

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
