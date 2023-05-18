/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:18:05 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/18 17:46:07 by zmakhkha         ###   ########.fr       */
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
	if (type == FILE_)
		printf("FILE");
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
	if (type == DIGITE)
		printf("DIGITE");
	if (type == AMP)
		printf("AMP");
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
			printf("(%s, %d)", t->str, t->fd);
			printf("->");
			t = t->prev;
		}
		printf("\n");
	}
}
