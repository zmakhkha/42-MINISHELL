/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:35:28 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/20 19:35:28 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

//Valid here doc delimiter
int	ft_valid_hd_delim(t_token *lst)
{
	if (lst)
		return (lst->type == WORD || \
		lst->type == DQ_COMM || lst->type == SQ_COMM);
	return (ERR);
}

//Check for the here doc delimiter
int	ft_check_hdoc(t_token *lst)
{
	int	i;

	i = SUCC;
	if (lst && lst->prev)
	{
		if (ft_getlast(lst)->type == HDOC)
			i = ERR;
		while (lst)
		{
			if (lst->type == HDOC && (\
				!ft_valid_hd_delim(lst->prev) || !lst->prev))
			{
				i = ERR;
				break ;
			}
			lst = lst->prev;
		}
	}
	return (i);
}
