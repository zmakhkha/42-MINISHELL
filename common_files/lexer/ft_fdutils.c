/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:37:24 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/26 07:32:32 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// joinfd
void	ft_fd_file(t_token **list)
{
	t_token	*lst;

	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && ((ft_isredirection(lst)) || lst->type == HDOC) \
		&& lst->prev->type == FILE_)
		{
			free (lst->str);
			lst->str = ft_strdup(lst->prev->str);
			ft_remove_tok(list, lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
}

// Read the file descriptor of the redirection
void	ft_readfd(t_token **list)
{
	t_token	*lst;

	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (lst->type == DIGITE) && (ft_isredirection(lst->prev)))
		{
			lst->fd = ft_atoi(lst->str);
			free(lst->str);
			lst->str = NULL;
			lst->type = lst->prev->type;
			ft_remove_tok(list, lst->prev);
		}
		lst = lst->prev;
	}
}
