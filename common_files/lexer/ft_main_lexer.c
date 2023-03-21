/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:06:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/21 19:18:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_main_lexer(t_token *lst)
{
	if (lst)
	{
		ft_position_it(&lst);
		ft_check_operators(lst);
		ft_check_hdoc(lst);
		ft_opperators(lst);
		ft_merge_words(&lst);
		ft_build_scomm(&lst);
		// ft_check_redirections(lst);
		ft_print_token(lst);
		ft_print_token_str(lst);
	}
}
