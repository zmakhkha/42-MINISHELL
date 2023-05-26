/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:06:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/26 15:25:08 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_main_lexer(t_token *lst)
{
	if (lst)
	{
		ft_detect_op(&lst);
		ft_readfd(&lst);
		ft_word_dig(&lst);
		ft_merge_sp(&lst);
		ft_detect_files(&lst);
		ft_fd_file(&lst);
		ft_swap_red(&lst);
		ft_swap_red2(&lst);
		ft_swap_red3(&lst);
		ft_merge_dig(&lst);
		if (ft_check_op(lst) == SUCC)
		{	
			ft_print_token_str(lst);
			ft_print_token(lst);
		}
		else
			printf("lexer error !! \n");
	}
}
