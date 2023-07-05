/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:22:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/05 20:46:10 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	d_quotes1(char *str, t_token **lst, int *a, int *b)
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
			ft_token_addback(lst, ft_add_token(s, QUOTE));
			*b += 1;
		}
		else if (*b == len)
			g_glob.g_status = ERR;
	}
}

void	s_quotes1(char *str, t_token **lst, int *a, int *b)
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
			ft_token_addback(lst, ft_add_token(s, QUOTE));
			*b += 1;
		}
		else if (*b == len)
			g_glob.g_status = ERR;
	}
}

int	ft_valid_word1(char c)
{
	return (!ft_is_quote(c) && !ft_is_whitespace_(c));
}

void	ft__strtok1(char *str, t_token **lst, int *a, int *b)
{
	if (!g_glob.g_status && str[*b] && str[*b] == '"')
		d_quotes(str, lst, a, b);
	else if (!g_glob.g_status && str[*b] && str[*b] == '\'')
		s_quotes1(str, lst, a, b);
}

void	ft_word1(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	while (str[(*b)] && ft_valid_word1(str[*b]))
		*b += 1;
	s = ft_substr(str, *a, *b - *a);
	ft_token_addback(lst, ft_add_token(s, WORD));
}
