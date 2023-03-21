/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:01:55 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/21 19:22:23 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_pr1(int a)
{
	if (a == WORD)
		return ("WORD");
	else if (a == PIPE)
		return ("PIPE");
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
	else if (a == DQ_COMM)
		return ("DQ_COMM");
	else if (a == SQ_COMM)
		return ("SQ_COMM");
	else if (a == DOLLAR)
		return ("DOLLAR");
	else if (a == QST)
		return ("QST");
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
	if (str[*b] && str[*b] == '"')
		d_quotes(str, lst, a, b);
	else if (str[*b] && str[*b] == '(')
		ft_prt(str, lst, a, b);
	else if (str[*b] && ft_is_moperator(str[*b]))
		ft_operators(str, lst, a, b);
	else if (str[*b] && (str[*b] == '>'))
		ft_operators2(str, lst, a, b);
	else if (str[*b] && str[*b] == '<')
		ft_operators3(str, lst, a, b);
	else if (str[*b] && ft_is_operators4(str[*b]))
		ft_operators4(str, lst, a, b);
	else
	{
		free(lst);
		ft_exit("Parse !!", 1);
	}
}

t_token	*ft_strtok(char *str)
{
	int		i;
	int		j;
	t_token	*lst;

	j = 0;
	lst = NULL;
	while (str[j] && !ft_forbidden(str[j]))
	{
		i = j;
		if (ft_is_whitespace(str[j]))
			ft_space(str, &lst, &i, &j);
		else if (ft_is_operators4(str[j]))
			ft_operators4(str, &lst, &i, &j);
		else if (ft_valid_word(str[j]))
			ft_word(str, &lst, &i, &j);
		else if (str[j] && str[j] == '\'')
			s_quotes(str, &lst, &i, &j);
		else
			ft__strtok(str, &lst, &i, &j);
	}
	return (lst);
}
