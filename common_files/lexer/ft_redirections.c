/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:47:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/22 17:31:57 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_isredirection(t_token *l)
{
	return (l->type == RE_IN || l->type == RE_OUT || \
	l->type == APPEND || l->type == HDOC);
}

void	ft_detect_files(t_token **lst)
{
	t_token	*tmp;

	if (lst)
	{
		tmp = *lst;
		while (tmp && tmp->prev)
		{
			if (ft_isredirection(tmp) && ((tmp->prev->type == WORD) || \
			(tmp->type == QUOTE)))
				tmp->prev->type = FILE_;
			tmp = tmp->prev;
		}
	}
}

int	ft_isvalidred(t_token *lst)
{
	int	ret;

	ret = SUCC;
	while (lst && lst ->prev)
	{
		if (ft_isredirection(lst) && \
		lst->prev->type != FILE_)
		{
			ret = ERR;
		}
	}
	return (ret);
}
