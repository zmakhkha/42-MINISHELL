/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:58:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/27 19:46:14 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// check if there is a big operator in list or no
int	ft_isthere_bop(t_token *lst)
{
	if (lst)
	{	
		lst = ft_getfirst(lst);
		while (lst)
		{
			if (ft_isbigoperators(lst))
				return (1);
			lst = lst->prev;
		}
	}
	return (0);
}

int	ft_isthere_pipe(t_token *lst)
{
	if (lst)
	{	
		lst = ft_getfirst(lst);
		while (lst)
		{
			if (lst->type == PIPE)
				return (1);
			lst = lst->prev;
		}
	}
	return (0);
}

void	ft_make_bigops(t_token **list)
{
	t_token *tail;

	if (list && ft_isthere_bop(*list))
	{
		tail = ft_getlast(*list);
		while (tail && !ft_isbigoperators(tail))
			tail = tail->next;
		if (tail->prev)
			tail->prev->next = NULL;
		tail->right = tail->prev;
		if (tail->next)
			tail->next->prev = NULL;
		tail->left = tail->next;
		tail->prev = NULL;
		tail->next = NULL;
		ft_make_bigops(&(tail->left));
		*list = tail;
	}
}

void	ft_make_pipes(t_token **list)
{
	t_token *tail;

	if (list && (*list)->type == PIPE)
	{
		tail = ft_getlast(*list);
		while (tail && (*list)->type != PIPE)
			tail = tail->next;
		if (tail->prev)
			tail->prev->next = NULL;
		tail->right = tail->prev;
		if (tail->next)
			tail->next->prev = NULL;
		tail->left = tail->next;
		tail->prev = NULL;
		tail->next = NULL;
		ft_make_pipes(&(tail->left));
		*list = tail;
	}
}

void	ft_print_tree(t_token *list)
{
	if (list)
	{
		ft_print_tree(list->left);
		printf("(%s, %d)->", list->str, list->type);
		ft_print_tree(list->right);
	}
}

void	ft_main_ast(t_token **list)
{
	printf("\n The  tree stage \n");
	ft_make_bigops(list);
	ft_make_pipes(list);
	ft_print_tree(*list);
	write(1, "\n", 1);
}