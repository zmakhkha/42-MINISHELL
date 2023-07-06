/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:06:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/06 18:57:27 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// Removed the ft_swap_red2(&lst);
void	ft_lexit(t_token *lst)
{
	if (!g_glob.g_status)
	{
		ft_op_space_(&lst);
		ft_fd_file(&lst);
		ft_sub_red(lst);
		ft_swap_red(&lst);
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
			s_tmp = ft_join_free(lst->str, ft_strdup(lst->prev->str));
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
	ft_lasterr(lst);
	ft_mergewords(&lst);
	ft_mergeword_num(&lst);
	ft_detect_op(&lst);
	ft_check_op(lst);
	if (!g_glob.g_status && lst)
	{
		ft_readfd(&lst);
		ft_word_dig(&lst);
		ft_merge_sp(&lst);
		ft_detect_files(&lst);
		ft_checkfiles(lst);
		ft_lexit(lst);
	}
}
