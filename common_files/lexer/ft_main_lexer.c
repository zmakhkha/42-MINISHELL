/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:06:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/13 19:05:15 by zmakhkha         ###   ########.fr       */
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
			(tmp->type == SPACE && (tmp->prev->type == WORD)) || (tmp->type \
			== WORD && ((tmp->prev->type == WORD) || (tmp->prev->type == QUOTE))) )
			{
				s_tmp = tmp->str;
				tmp->str = ft_join_free(tmp->str, tmp->prev->str);
				free(s_tmp);
				ft_delete_prev_token(&tmp);
				continue ;
			}
			tmp = tmp->prev;
		}
	}
}

void	ft_joint_trim_space(t_token **lst)
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
				ft_delete_prev_token(&tmp);
				continue ;
			}
			tmp = tmp->prev;
		}
	}
}

void ft_readfd(t_token **list)
{
	t_token *lst;
	t_token *tmp;
	int		i;

	i = 0;
	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if (ft_isdigit(lst->str[0]) && (ft_isredirection(lst->prev)))
		{
			i = 1;
			lst->prev->fd = ft_atoi(lst->str);
			// ft_remove_tok(&lst);
			tmp = lst;
			lst = lst->prev;
			free (tmp->str);
			free (tmp);
			tmp = NULL;
			// puts("sa\n\n\n");
		}
		else
			lst = lst->prev;
	}
	if (i)
		*list = (*list)->prev;
}

void	ft_main_lexer(t_token *lst)
{
	int	ret;

	ret = SUCC;
	if (lst)
	{
		ft_readfd(&lst);
		if (lst == NULL)
			printf("%s\n\n\n", lst->str);
		ft_position_it(&lst);
		ft_joint_trim_space(&lst);
		ft_detect_files(&lst);
		ft_merge_sw(&lst);
		if ( ret == ft_check_redirections(lst) && ret == ft__opperators(lst) && \
		ret == ft_check_operators(lst) && ret == ft_check_hdoc(lst) && \
		ret == ft_opperators(lst) && ret == ft_subshells(lst))
		{
			ft_print_token_str(lst);
			ft_print_token(lst);
			ft_check_redirections(lst);
		}
		// else
		// 	printf("lexer error !!");
	}
}
