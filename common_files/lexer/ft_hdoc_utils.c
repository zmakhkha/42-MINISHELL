/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hdoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:31:47 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 19:52:26 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_twotoone(char **table)
{
	int		i;
	char	*res;
	char	*tmp;

	res = NULL;
	tmp = NULL;
	i = -1;
	while (table && table[++i])
	{
		tmp = ft_join_free(res, table[i]);
		res = ft_join_free(tmp, ft_strdup(" "));
		free(tmp);
	}
	ft_free_2dstr(table);
	return (res);
}

//Valid here doc delimiter
int	ft_valid_hd_delim(t_token *lst)
{
	if (lst)
		return (lst->type == WORD || \
		lst->type == FILE_);
	return (0);
}
