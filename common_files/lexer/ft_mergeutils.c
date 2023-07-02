/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergeutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:36:10 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 19:53:42 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_rm_space_(t_token **list)
{
	t_token	*lst;

	lst = ft_getfirst(*list);
	while (lst)
	{
		if (lst->type == SPACE)
			ft_remove_tok(list, lst);
		if (lst)
			lst = lst->prev;
	}
}

void	ft_digtoword(t_token **list)
{
	t_token	*lst;

	lst = ft_getfirst(*list);
	while (lst)
	{
		if (lst->type == DIGITE)
			lst->type = WORD;
		lst = lst->prev;
	}
}

void	ft_merge_sp(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	ft_digtoword(list);
	lst = *list;
	while (lst && lst->prev)
	{
		if ((lst && (lst->type == SPACE) && (lst->prev->type == WORD || \
		lst->prev->type == DIGITE || lst->prev->type == SPACE)) || \
		(lst && (lst->type == WORD) && (\
		lst->prev->type == DIGITE || lst->prev->type == SPACE)))
		{
			s_tmp = ft_join_free(lst->str, ft_strdup(lst->prev->str));
			lst->str = s_tmp;
			lst->type = WORD;
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
}

// to add ft_rm_space(list); before lst = *list; if we need to
void	ft_merge_dig(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst && lst->prev)
	{
		if ((lst && (lst->type == DIGITE) && (lst->prev->type == WORD)) || \
			(lst->type == WORD && lst->prev->type == DIGITE) || \
			(lst->type == WORD && lst->prev->type == WORD))
		{
			s_tmp = ft_join_free(lst->str, ft_strdup(lst->prev->str));
			lst->str = s_tmp;
			lst->type = WORD;
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
	lst = *list;
}

// merge digits and words only
void	ft_word_dig(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (((lst->type == DIGITE) && (lst->prev->type == WORD)) || \
		((lst->type == WORD) && (lst->prev->type == DIGITE))))
		{
			s_tmp = ft_join_free(lst->str, ft_strdup(lst->prev->str));
			lst->str = s_tmp;
			lst->type = WORD;
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
	lst = *list;
}
