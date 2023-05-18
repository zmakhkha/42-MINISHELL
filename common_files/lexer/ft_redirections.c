/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirections.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:47:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/18 17:20:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_isredirection(t_token *l)
{
	return (l->type == RE_IN || l->type == RE_OUT || \
	l->type == APPEND);
}

void	ft_detect_files(t_token **lst)
{
	t_token	*tmp;

	if (lst)
	{
		tmp = *lst;
		while (tmp && tmp->prev)
		{
			if ((ft_isredirection(tmp) || tmp->type == HDOC) && ((tmp->prev->type == WORD)))
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
