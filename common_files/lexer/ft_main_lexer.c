/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:06:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/22 16:51:32 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// merge spaces with words
void	ft_merge_sw(t_token **lst)
{
	t_token	*tmp;
	char	*s_tmp;

	if (lst)
	{
		tmp = *lst;
		while (tmp && tmp->prev)
		{
			if ((tmp->type == WORD && (tmp->prev->type == SPACE)) || \
			(tmp->type == SPACE && (tmp->prev->type == WORD)))
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

void	ft_joint_trim(t_token **lst)
{
	t_token	*tmp;
	char	*s_tmp;

	if (lst && *lst)
	{
		tmp = *lst;
		while (tmp && tmp->prev)
		{
			if (!(tmp->type == SPACE) && (tmp->prev->type == SPACE))
			{
				s_tmp = ft_join_free(tmp->str, tmp->prev->str);
				free(tmp->str);
				tmp->str = ft_strtrim(s_tmp, " ");
				free(s_tmp);
				ft_delete_next_token(&tmp);
				continue ;
			}
			tmp = tmp->prev;
		}
	}
}

void	ft_main_lexer(t_token *lst)
{
	int	ret;

	ret = SUCC;
	if (lst)
	{
		ft_position_it(&lst);
		ft_joint_trim(&lst);
		ft_detect_files(&lst);
		ft_merge_sw(&lst);
		if ( ret == ft_check_redirections(lst) && ret == ft__opperators(lst) && \
		ret == ft_check_operators(lst) && ret == ft_check_hdoc(lst) && \
		ret == ft_opperators(lst))
		{
			// ft_build_scomm(&lst);
			ft_print_token_str(lst);
			ft_print_token(lst);
			// ft_check_redirections(lst);
		}
		// else
		// 	printf("lexer error !!");
	}
}
