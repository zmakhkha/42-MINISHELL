/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:43:14 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/18 10:25:14 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_forbidden(char c)
{
	if (c == ';' || c == '\\')
		ft_exit("unsupported character\n", 1);
	return (0);
}

int	ft_is_operators4(char c)
{
	return (c == '?' || c == '$' || c == '*');
}

void	ft_operators4(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (str[*b] && str[*b] == '?')
	{
		*b += 1;
		s = ft_substr(str, *a, *b + 1);
		ft_token_addback(lst, ft_add_token(s, QST));
	}
	if (str[*b] && str[*b] == '$')
	{
		*b += 1;
		s = ft_substr(str, *a, *b + 1);
		ft_token_addback(lst, ft_add_token(s, DOLLAR));
	}
	if (str[*b] && str[*b] == '*')
	{
		*b += 1;
		s = ft_substr(str, *a, *b + 1);
		ft_token_addback(lst, ft_add_token(s, W_CARD));
	}
}
