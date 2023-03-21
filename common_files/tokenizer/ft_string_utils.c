/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:26:38 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/21 19:20:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_word(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	while (str[(*b)] && ft_valid_word(str[*b]))
		*b += 1;
	s = ft_substr(str, *a, *b - *a);
	ft_token_addback(lst, ft_add_token(s, WORD));
}

void	d_quotes(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && str[*b] == '"')
	{
		*b += 1;
		while (str[*b] && str[*b] != '"')
			*b += 1;
		if (str[*b] == '"')
		{
			s = ft_substr(str, *a, *b - *a + 1);
			ft_token_addback(lst, ft_add_token(s, WORD));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			ft_exit("Double Quotes error !!\n", 1);
		}
	}
}

void	s_quotes(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && str[*b] == '\'')
	{
		*b += 1;
		while (str[*b] && str[*b] != '\'')
			*b += 1;
		if (str[*b] == '\'')
		{
			s = ft_substr(str, *a, *b - *a + 1);
			ft_token_addback(lst, ft_add_token(s, WORD));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			ft_exit("Signle Quotes error !!\n", 1);
		}
	}
}

void	ft__operators(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (ft_validouble(str + *b, '|'))
	{
		s = ft_substr(str, *a, 2);
		ft_token_addback(lst, ft_add_token(s, OR));
		*b += 2;
	}
	else if (str[*b] == '|')
	{
		s = ft_substr(str, *a, 1);
		ft_token_addback(lst, ft_add_token(s, PIPE));
		*b += 1;
	}
}

void	ft_operators(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (ft_voperator(str + *b, '|'))
	{
		ft__operators(str, lst, a, b);
	}
	else if (ft_voperator(str + *b, '&'))
	{
		if (ft_validouble(str + *b, '&'))
		{
			s = ft_substr(str, *a, 2);
			ft_token_addback(lst, ft_add_token(s, AND));
			*b += 2;
		}
		else if (str[*b] == '&')
			ft_exit("& error !!\n", 1);
	}
	else
		ft_exit("PIPE or OR error !!\n", 1);
}
