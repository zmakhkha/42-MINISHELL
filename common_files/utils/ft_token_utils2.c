/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:18:05 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/21 15:47:28 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_position_it(t_token **lst)
{
	int		i;
	t_token	*pos;

	i = 0;
	if (lst && *lst)
	{
		pos = *lst;
		while (pos)
		{
			pos->index = i;
			i++;
			pos = pos->prev;
		}
	}
}

void	ft_print_utils(int type)
{
	if (type == WORD)
		printf("WORD");
	if (type == PIPE)
		printf("PIPE");
	if (type == SPACE)
		printf("SPACE");
	if (type == SUBSHELL)
		printf("SUBSHELL");
	if (type == AND)
		printf("AND");
	if (type == OR)
		printf("OR");
	if (type == RE_IN)
		printf("RE_IN");
	if (type == RE_OUT)
		printf("RE_OUT");
	if (type == HDOC)
		printf("HDOC");
	if (type == APPEND)
		printf("APPEND");
	if (type == W_CARD)
		printf("W_CARD");
	if (type == DQ_COMM)
		printf("DQ_COMM");
	if (type == SQ_COMM)
		printf("SQ_COMM");
	if (type == DOLLAR)
		printf("DOLLAR");
	if (type == QST)
		printf("QST");
}

void	ft_print_token(t_token *t)
{
	if (t)
	{
		while (t)
		{
			ft_print_utils(t->type);
			printf("->");
			t = t->prev;
		}
		printf("\n");
	}
}

void	ft_print_token_str(t_token *t)
{
	if (t)
	{
		while (t)
		{
			printf("(%s)", t->str);
			printf("->");
			t = t->prev;
		}
		printf("\n");
	}
}
