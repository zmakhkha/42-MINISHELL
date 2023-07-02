/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:19:15 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 19:52:57 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_lasterr(t_token *lst)
{
	if (lst)
	{
		if (ft_getlast(lst)->type == RE_IN || ft_getlast(lst)->type == RE_OUT
			|| ft_getlast(lst)->type == APPEND)
			g_glob.g_status = ERR;
	}
}

void	ft_singleerr(t_token *lst)
{
	if (lst && !lst->prev)
	{
		if (lst->type == RE_IN || lst->type == RE_OUT || lst->type == APPEND)
			g_glob.g_status = ERR;
	}
}

void	ft_checksyntax(t_token *lst)
{
	ft_succop(lst);
	ft_syntaxerr(lst);
	ft_operrors(lst);
}

void	ft_checkfiles(t_token *lst)
{
	while (lst && lst->prev)
	{
		if ((ft_isredirection(lst) || lst->type == HDOC)
			&& (lst->prev->type != FILE_))
		{
			g_glob.g_status = ERR;
			break ;
		}
		lst = lst->prev;
	}
}

// to solve the case ls1>haha
void	ft_mergeword_num(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (lst->type == WORD) && (lst->prev->type == DIGITE))
		{
			s_tmp = ft_join_free(lst->str, ft_strdup(lst->prev->str));
			lst->str = s_tmp;
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
}
