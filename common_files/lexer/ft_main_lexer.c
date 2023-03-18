/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:06:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/18 17:07:04 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_position_it(t_token **lst)
{
	int		i;
	t_token	*pos;

	i = 0;
	if (lst && *lst)
	{
		pos = *lst;
		while (pos)
		{
			pos->index = i;
			i++;
			pos = pos->prev;
		}
	}
}

void	ft_main_lexer(t_token *lst)
{
	if (lst)
	{
		ft_position_it(&lst);
		ft_check_operators(lst);
		ft_check_redirections(lst);
	}
}
