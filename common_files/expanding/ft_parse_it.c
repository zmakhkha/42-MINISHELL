/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 04:22:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/01 15:55:29 by zmakhkha         ###   ########.fr       */
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

t_token	*ft_strtok1(char *str)
{
	int		i;
	int		j;
	t_token	*lst;

	j = 0;
	lst = NULL;
	ft_forbidden(str);
	while (str && str[j] && !g_glob.g_status)
	{
		if (i == j)
			j++;
		else
			i = j;
		if (ft_is_whitespace_(str[j]))
			ft_space_(str, &lst, &i, &j);
		else if (ft_valid_word1(str[j]))
			ft_word1(str, &lst, &i, &j);
		else
			ft__strtok1(str, &lst, &i, &j);
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
