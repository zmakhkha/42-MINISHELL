/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:01:55 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/26 15:10:31 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_pr1(int a)
{
	if (a == WORD)
		return ("WORD");
	else if (a == PIPE)
		return ("PIPE");
	else if (a == FILE_)
		return ("FILE");
	else if (a == SPACE)
		return ("SPACE");
	else if (a == SUBSHELL)
		return ("SUBSHELL");
	else if (a == AND)
		return ("AND");
	else if (a == OR)
		return ("OR");
	else if (a == RE_IN)
		return ("RE_IN");
	else if (a == RE_OUT)
		return ("RE_OUT");
	else if (a == HDOC)
		return ("HDOC");
	else if (a == APPEND)
		return ("APPEND");
	else if (a == W_CARD)
		return ("W_CARD");
	else if (a == AMP)
		return ("AMP");
	return ("NULL");
}

void	ft_pr(t_token *lst)
{
	if (lst)
	{
		while (lst)
		{
			printf("%s : %s\n", ft_pr1(lst->type), lst->str);
			lst = lst->prev;
		}
	}
}

void	ft__strtok(char *str, t_token **lst, int *a, int *b)
{
	if (!g_status && str[*b] && ft_isdigit(str[*b]))
		ft_digits(str, lst, a, b);
	else if (!g_status && str[*b] && str[*b] == '"')
		d_quotes(str, lst, a, b);
	else if (!g_status && str[*b] && str[*b] == '\'')
		s_quotes(str, lst, a, b);
	else if (!g_status && str[*b] && (str[*b] == '(' || str[*b] == ')'))
		ft_prt(str, lst, a, b);
	else if (!g_status && str[*b] && ft_is_moperator(str[*b]))
		ft_operators(str, lst, a, b);
	else if (!g_status && str[*b] && (str[*b] == '>'))
		ft_operators2(str, lst, a, b);
	else if (!g_status && str[*b] && str[*b] == '<')
		ft_operators3(str, lst, a, b);
	else if (g_status)
		printf("unrecognized status!!\n");
}

t_token	*ft_strtok(char *str)
{
	int		i;
	int		j;
	t_token	*lst;

	j = 0;
	lst = NULL;
	ft_forbidden(str);
	while (str[j] && !g_status)
	{
		i = j;
		if (ft_is_whitespace(str[j]))
			ft_space(str, &lst, &i, &j);
		else if (ft_valid_word(str[j]))
			ft_word(str, &lst, &i, &j);
		else
			ft__strtok(str, &lst, &i, &j);
	}
	if (g_status == SUCC)
		return (lst);
	else
	{
		lst = ft_getfirst(lst);
		ft_free_token(&lst);
		return (NULL);
	}
}

// t_token	*ft_main_token(t_token *lst)
// {
// 	if (lst)
// 	{
// 		ft_print_token_str(lst);
// 		ft_print_token(lst);
// 	}
// 	return (NULL);
// }
