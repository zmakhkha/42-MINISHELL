/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:01:55 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/15 18:18:56 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_pr(int a)
{
	if (a == WORD)
		printf("WORD");
	else if (a == PIPE)
		printf("PIPE");
	else if (a == SUBSHELL)
		printf("SUBSHELL");
	else if (a == COMMAND)
		printf("COMMAND");
	else if (a == AND)
		printf("AND");
	else if (a == OR)
		printf("OR");
	else if (a == RE_IN)
		printf("RE_IN");
	else if (a == RE_OUT)
		printf("RE_OUT");
	else if (a == HDOC)
		printf("HDOC");
	else if (a == APPEND)
		printf("APPEND");
	else if (a == W_CARD)
		printf("W_CARD");
	else if (a == DQ_COMM)
		printf("DQ_COMM");
	else if (a == SQ_COMM)
		printf("SQ_COMM");
}

t_token	*ft_add_token(char *str, int type)
{
	t_token	*tmp;

	if (!str)
		return (NULL);
	tmp = (t_token *) malloc(sizeof(t_token));
	if (!tmp)
		ft_exit("Token allocation failed", 1);
	tmp->str = str;
	tmp->type = type;
	tmp->prev = NULL;
	return (tmp);
}

void	ft_token_addback(t_token **lst, t_token *new)
{
	t_token	*pos;

	if (*lst == NULL)
		*lst = new;
	else
	{
		pos = *lst;
		while (pos -> prev != NULL)
			pos = pos -> prev;
		pos -> prev = new;
	}
}

void	ft_free_token(t_token **t)
{
	t_token	*tmp;

	if (t && *t)
	{
		if ((*t)-> prev == NULL)
			free (*t);
		else
		{
			while ((*t)->prev)
			{
				tmp = *t;
				(*t) = (*t)->prev;
				free (tmp);
			}
			free ((*t));
		}
	}
}
