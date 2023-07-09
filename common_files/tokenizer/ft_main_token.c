/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:01:55 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/07 04:41:09 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft__strtok(char *str, t_token **lst, int *a, int *b)
{
	if (!g_glob.g_status && str[*b] && ft_isdigit(str[*b]))
		ft_digits(str, lst, a, b);
	else if (!g_glob.g_status && str[*b] && str[*b] == '"')
		d_quotes(str, lst, a, b);
	else if (!g_glob.g_status && str[*b] && str[*b] == '\'')
		s_quotes(str, lst, a, b);
	else if (!g_glob.g_status && str[*b] && (str[*b] == '(' || str[*b] == ')'))
		ft_prt(str, lst, a, b);
	else if (!g_glob.g_status && str[*b] && ft_is_moperator(str[*b]))
		ft_operators(str, lst, a, b);
	else if (!g_glob.g_status && str[*b] && (str[*b] == '>'))
		ft_operators2(str, lst, a, b);
	else if (!g_glob.g_status && str[*b] && str[*b] == '<')
		ft_operators3(str, lst, a, b);
	if (g_glob.g_status == ERR)
	{
		g_glob.g_status_exit = 258;
		printf("Tokenizer Error!!\n");
	}
}

t_token	*ft_strtok(char *str)
{
	int		i;
	int		j;
	t_token	*lst;

	j = 0;
	lst = NULL;
	ft_forbidden(str);
	while (str && str[j] && !g_glob.g_status)
	{
		i = j;
		if (ft_is_whitespace_(str[j]))
			ft_space_(str, &lst, &i, &j);
		else if (ft_valid_word(str[j]))
			ft_word(str, &lst, &i, &j);
		else
			ft__strtok(str, &lst, &i, &j);
	}
	if (g_glob.g_status == SUCC)
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
