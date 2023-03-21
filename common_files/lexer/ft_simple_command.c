/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:53:11 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/21 19:17:45 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_join_space(t_token **lst)
{
	t_token	*tmp;
	char	*s_tmp;

	if (lst)
	{
		tmp = *lst;
		while (tmp && tmp->prev)
		{
			if (tmp->type == WORD && tmp->prev->type == SPACE)
			{
				s_tmp = tmp->str;
				tmp->str = ft_join_free(tmp->str, " ");
				free(s_tmp);
				ft_delete_next_token(&tmp);
				continue ;
			}
			tmp = tmp->prev;
		}
	}
}

void	ft_merge_words(t_token **lst)
{
	t_token	*tmp;
	char	*s_tmp;

	if (lst)
	{
		tmp = *lst;
		while (tmp && tmp->prev)
		{
			if (tmp->type == WORD && !(tmp->prev->type == AND || \
			tmp->prev->type == OR || tmp->prev->type == PIPE || \
			tmp->prev->type == SUBSHELL))
			{
				s_tmp = tmp->str;
				tmp->str = ft_join_free(tmp->str, tmp->prev->str);
				free(s_tmp);
				ft_delete_next_token(&tmp);
				continue ;
			}
			tmp = tmp->prev;
		}
	}
}

void	ft_build_scomm(t_token **lst)
{
	ft_join_space(lst);
	ft_merge_words(lst);
}
