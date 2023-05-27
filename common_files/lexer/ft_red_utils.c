/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:20:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/27 17:30:15 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// swap redirections
void	ft_swap_red(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if (((lst->type == WORD || lst->type == SUBSHELL) && \
		(ft_isredirection(lst->prev) || lst->prev->type == HDOC)))
		{
			ft_swap(lst);
			ft_merge_dig(list);
			lst = *list;
			continue ;
		}
		lst = lst->prev;
	}
	*list = ft_getfirst(*list);
}

// swap redirections HDOC -> REDIRECTIONS
void	ft_swap_red2(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if (ft_isredirection(lst) && lst->prev->type == HDOC)
		{
			ft_swap(lst);
			ft_merge_dig(list);
			lst = *list;
			continue ;
		}
		lst = lst->prev;
	}
	*list = ft_getfirst(*list);
}

// swap redirections RE_IN -> RE_OUT
void	ft_swap_red3(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if ((lst->type == RE_OUT || lst->type == APPEND) \
		&& lst->prev->type == RE_IN)
		{
			ft_swap(lst);
			ft_merge_dig(list);
			lst = *list;
			continue ;
		}
		lst = lst->prev;
	}
	*list = ft_getfirst(*list);
}
