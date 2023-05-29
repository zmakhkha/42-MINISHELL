/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:58:35 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/22 14:25:15 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	ft_lstdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->key);
	free(lst);
}
