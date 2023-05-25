/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_lexer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:06:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/25 23:51:51 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_merge_sp(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst)
	{
		if (lst->type == DIGITE)
			lst->type = WORD;
		lst = lst->prev;
	}
	lst = *list;
	while (lst && lst->prev)
	{
		if ((lst && (lst->type == SPACE) && (lst->prev->type == WORD ||\
		lst->prev->type == DIGITE || lst->prev->type == SPACE)) ||
		(lst && (lst->type == WORD) && ( \
		lst->prev->type == DIGITE || lst->prev->type == SPACE)))
		{
			s_tmp = ft_join_free(lst->str, lst->prev->str);
			free(lst->str);
			lst->str = s_tmp;
			lst->type = WORD;
			ft_remove_tok(&lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
}

void	ft_merge_dig(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst && lst->prev)
	{
		if ((lst && (lst->type == DIGITE) && (lst->prev->type == WORD)) || \
			(lst->type == WORD && lst->prev->type == DIGITE) || \
			(lst->type == WORD && lst->prev->type == WORD))
		{
			s_tmp = ft_join_free(lst->str, lst->prev->str);
			free(lst->str);
			lst->str = s_tmp;
			lst->type = WORD;
			ft_remove_tok(&lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
	lst = *list;
	while (lst)
	{
		if (lst->type == SPACE)
			ft_remove_tok(&lst);
			if (lst)
				lst = lst->prev;
	}
}

void	ft_word_dig(t_token **list)
{
	t_token	*lst;
	char	*s_tmp;

	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (((lst->type == DIGITE) && (lst->prev->type == WORD)) || \
		((lst->type == WORD) && (lst->prev->type == DIGITE))))
		{
			s_tmp = ft_join_free(lst->str, lst->prev->str);
			free(lst->str);
			lst->str = s_tmp;
			lst->type = WORD;
			ft_remove_tok(&lst->prev);
			continue ;
		}
		lst = lst->prev;
	}
	lst = *list;
	// while (lst)
	// {
	// 	if (lst->type == SPACE)
	// 		ft_remove_tok(&lst);
	// 		if (lst)
	// 			lst = lst->prev;
	// }
}

void	ft_readfd(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (lst->type == DIGITE) && (ft_isredirection(lst->prev)))
		{
			lst->fd = ft_atoi(lst->str);
			free(lst->str);
			lst->str = NULL;
			lst->type = lst->prev->type;
			ft_remove_tok(&lst->prev);
		}
		lst = lst->prev;
	}
}
// joinfd
void	ft_fd_file(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && ((ft_isredirection(lst)) || lst->type == HDOC) && lst->prev->type == FILE_)
		{
			free (lst->str);
			lst->str = ft_strdup(lst->prev->str);
			ft_remove_tok(&lst->prev);
		}
		lst = lst->prev;
	}
}

// swap redirections
void	ft_swap_red(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if ((lst->type == WORD && (ft_isredirection(lst->prev) || lst->prev->type == HDOC)))
		{
			ft_swap(lst);
			ft_merge_dig(list);
			lst = *list;
			continue ;
		}
		lst = lst->prev;
	}
	*list = ft_getfirst(*list);
}
// swap redirections HDOC -> REDIRECTIONS
void	ft_swap_red2(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if (ft_isredirection(lst) && lst->prev->type == HDOC)
		{
			ft_swap(lst);
			ft_merge_dig(list);
			lst = *list;
			continue ;
		}
		lst = lst->prev;
	}
	*list = ft_getfirst(*list);
}
// swap redirections RE_IN -> RE_OUT
void	ft_swap_red3(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if ((lst->type == RE_OUT || lst->type == APPEND) && lst->prev->type == RE_IN)
		{
			ft_swap(lst);
			ft_merge_dig(list);
			lst = *list;
			continue ;
		}
		lst = lst->prev;
	}
	*list = ft_getfirst(*list);
}

// Detects PIPE and AND operators
void	ft_detect_op(t_token **list)
{
	t_token	*lst;
	t_token	*tmp;

	tmp = NULL;
	lst = *list;
	while (lst && lst->prev)
	{
		if (lst && (lst->type == PIPE) && (lst->prev->type == PIPE))
		{
			lst->type = OR;
			free(lst->str);
			lst->str = ft_strdup("||");
			ft_remove_tok(&lst->prev);
		}
		else if (lst && (lst->type == AMP) && (lst->prev->type == AMP))
		{
			lst->type = AND;
			free(lst->str);
			lst->str = ft_strdup("&&");
			ft_remove_tok(&lst->prev);
		}
		lst = lst->prev;
	}
}

void	ft_main_lexer(t_token *lst)
{
	int	ret;

	ret = SUCC;
	if (lst)
	{
		ft_detect_op(&lst);
		ft_readfd(&lst);
		ft_word_dig(&lst);
		ft_merge_sp(&lst);
		ft_detect_files(&lst);
		ft_fd_file(&lst);
		ft_swap_red(&lst);
		ft_swap_red2(&lst);
		ft_swap_red3(&lst);
		ft_merge_dig(&lst);

		// if (ft_check_op(lst) == SUCC)
		// {	
		ft_print_token_str(lst);
		ft_print_token(lst);
		// }
		// else
		// 	printf("lexer error !! \n");
	}
}
