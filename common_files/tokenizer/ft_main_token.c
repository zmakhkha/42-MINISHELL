/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:01:55 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/22 17:01:03 by zmakhkha         ###   ########.fr       */
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
	else if (a == QUOTE)
		return ("QUOTE");
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

int	ft__strtok(char *str, t_token **lst, int *a, int *b)
{
	int	ret;

	ret = SUCC;
	if (str[*b] && str[*b] == '"')
		ret = d_quotes(str, lst, a, b);
	else if (str[*b] && str[*b] == '(')
		ret = ft_prt(str, lst, a, b);
	else if (str[*b] && ft_is_moperator(str[*b]))
		ret = ft_operators(str, lst, a, b);
	else if (str[*b] && (str[*b] == '>'))
		ret = ft_operators2(str, lst, a, b);
	else if (str[*b] && str[*b] == '<')
		ret = ft_operators3(str, lst, a, b);
	else if (str[*b] && ft_is_operators4(str[*b]))
		ft_operators4(str, lst, a, b);
	else if (str[*b] && str[*b] == '\'')
		ret = s_quotes(str, lst, a, b);
	else
	{
		// free(lst);
		// ft_free_token(lst);
		printf("Tokenization !!\n");
		ret = ERR;
	}
	return (ret);
}

t_token	*ft_strtok(char *str)
{
	int		i;
	int		j;
	int		ret;
	t_token	*lst;

	j = 0;
	ret = SUCC;
	lst = NULL;
	ret = ft_forbidden(str[j]);
	while (str[j] && (ret == SUCC))
	{
		i = j;
		if (ft_is_whitespace(str[j]))
			ft_space(str, &lst, &i, &j);
		else if (ft_is_operators4(str[j]))
			ft_operators4(str, &lst, &i, &j);
		else if (ft_valid_word(str[j]))
			ft_word(str, &lst, &i, &j);
		else
			ret = ft__strtok(str, &lst, &i, &j);
	}
	if (ret == SUCC)
		return (lst);
	else
		return (NULL);
}
