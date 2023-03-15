/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:58:29 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/15 18:27:33 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_is_operator2(char c)
{
	return (c == '<' || c == '>');
}

void	ft_operators3(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && str[*b] == '<')
	{
		s = ft_substr(str, *a, *b + 1);
		ft_token_addback(lst, ft_add_token(s, RE_IN));
		*b += 1;
	}
	else if (str[*b] && str[*b] == '>')
	{
		s = ft_substr(str, *a, *b + 1);
		ft_token_addback(lst, ft_add_token(s, RE_OUT));
		*b += 1;
	}
	if (s)
		free (s);
}
void	ft_operators2(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	len = ft_strlen(str);
	s = NULL;
	if (str[*b] && str[*b + 1] && str[*b] == '<' && str[*b + 1] == '<')
	{
		s = ft_substr(str, *a, *a + 2);
		ft_token_addback(lst, ft_add_token(s, HDOC));
		*b += 2;
	}
	else if (str[*b] && str[*b + 1] && str[*b] == '>' && str[*b + 1] == '>')
	{
		s = ft_substr(str, *a, *b + 2);
		ft_token_addback(lst, ft_add_token(s, APPEND));
		*b += 2;
	}
	else if (str[*b] && (str[*b] == '<' || str[*b] == '>'))
		ft_operators3(str, lst, a, b);
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
	return (lst);
}
