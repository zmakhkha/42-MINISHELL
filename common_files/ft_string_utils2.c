/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:58:29 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/17 00:39:36 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_is_operator2(char c)
{
	return (c == '<' || c == '>');
}

void	ft_operators2(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (ft_voperator(str + *b,'>'))
	{
		if (ft_validouble(str + *b, '>'))
		{	
			s = ft_substr(str, *a, *b + 1);
			ft_token_addback(lst, ft_add_token(s, APPEND));
			*b += 2;
		}
		else if (str[*b] == '>')
		{
			s = ft_substr(str, *a, *b + 1);
			ft_token_addback(lst, ft_add_token(s, RE_OUT));
			*b += 1;
		}
	}
	if (s)
		free (s);
}

void	ft_operators3(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (ft_voperator(str + *b,'<'))
	{
		if (ft_validouble(str + *b, '<'))
		{	
			s = ft_substr(str, *a, *b + 1);
			ft_token_addback(lst, ft_add_token(s, HDOC));
			*b += 2;
		}
		else if (str[*b] == '<')
		{
			s = ft_substr(str, *a, *b + 1);
			ft_token_addback(lst, ft_add_token(s, RE_IN));
			*b += 1;
		}
	}
	else
		ft_exit("Operators 2 Error !!", 1);
	if (s)
		free (s);
}

t_token	*ft_strtok(char *str)
{
	int		i;
	int		j;
	t_token	*lst;

	j = 0;
	lst = NULL;
	while (str[j])
	{
		while (ft_is_whitespace(str[j]))
			j++;
		i = j;
		if (ft_is_valid_comm(str[j]))
			white_comm(str, &lst, &i, &j);
		else if (str[j] && str[j] == '\'')
			s_quotes(str, &lst, &i, &j);
		else if (str[j] && str[j] == '"')
			d_quotes(str, &lst, &i, &j);
		else if (str[j] == '(')
			ft_prt(str, &lst, &i, &j);
		else if (str[j] && ft_is_operator(str[j]))
			ft_operators(str, &lst, &i, &j);
		else if (str[j] && ft_is_operator2(str[j]))
			ft_operators2(str, &lst, &i, &j);
		else
			return (free(lst), ft_exit("Parse !!", 1), NULL);
	}
	else
		ft_exit("Operators 2 Error !!", 1);
	return (lst);
}
