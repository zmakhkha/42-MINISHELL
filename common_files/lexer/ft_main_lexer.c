/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:06:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/26 17:25:36 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

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

void	ft_main_lexer(t_token *lst)
{
	// ft_three(lst);
	ft_detect_op(&lst);
	ft_check_op(lst);
	ft_operrors(lst);
	if (!g_status && lst)
	{
		ft_readfd(&lst);
		ft_word_dig(&lst);
		ft_merge_sp(&lst);
		ft_detect_files(&lst);
		ft_checkfiles(lst);
		if (!g_status)
		{
			ft_op_space(&lst);
			ft_fd_file(&lst);
			ft_swap_red(&lst);
			ft_swap_red2(&lst);
			ft_swap_red3(&lst);
			ft_merge_dig(&lst);
			ft_print_token_str(lst);
			ft_print_token(lst);
		}
		if (g_status)
			printf("error\n\n");
	}
	else
		printf("lexer error !! \n");
}
