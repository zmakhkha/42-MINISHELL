/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:06:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/23 12:07:56 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_lasterr(t_token *lst)
{
	if (lst)
	{
		if (ft_getlast(lst)->type == RE_IN || ft_getlast(lst)->type == RE_OUT\
		|| ft_getlast(lst)->type == APPEND)
		g_status = ERR;
	}
}

void	ft_singleerr(t_token *lst)
{
	if (lst && !lst->prev)
	{
		if (lst->type == RE_IN || lst->type == RE_OUT\
		|| lst->type == APPEND)
		g_status = ERR;
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
		if ((ft_isredirection(lst) || lst->type == HDOC) && \
		(lst->prev->type != FILE_))
		{
			g_status = ERR;
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
			s_tmp = ft_join_free(lst->str, lst->prev->str);
			free(lst->str);
			lst->str = s_tmp;
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
}

//  Add this to print to tokens after the lexing
		// else
		// {
		// 	ft_print_token_str(lst);
		// 	ft_print_token(lst);
		// }		
void	ft_lexit(t_token *lst)
{
	if (!g_status)
	{
		ft_op_space(&lst);
		ft_fd_file(&lst);
		ft_lasterr(lst);
		ft_sub_red(lst);
		ft_swap_red(&lst);
		ft_swap_red2(&lst);
		ft_merge_dig(&lst);
		ft_checksyntax(lst);	
	}
}

void	ft_mergewords(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (lst->type == WORD) && (lst->prev->type == WORD))
		{
			s_tmp = ft_join_free(lst->str, lst->prev->str);
			free(lst->str);
			detect(s_tmp);
			lst->str = s_tmp;
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
}

// to add ft_swap_red3(&lst) after ft_swap_red2(&lst); if we need to
void	ft_main_lexer(t_token *lst)
{
	ft_mergewords(&lst);
	ft_mergeword_num(&lst);
	ft_detect_op(&lst);
	ft_check_op(lst);
	if (!g_status && lst)
	{
		ft_readfd(&lst);
		ft_word_dig(&lst);
		ft_merge_sp(&lst);
		ft_detect_files(&lst);
		ft_checkfiles(lst);
		ft_lexit(lst);
	}
	else
		printf("lexer error2 !!\n");
}
