/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:26:38 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/22 13:21:23 by zmakhkha         ###   ########.fr       */
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

int	d_quotes(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;
	int		ret;

	s = NULL;
	ret = SUCC;
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
		{
			ft_free_token(lst);
			printf("Double Quotes error !!\n");
			ret = ERR;
		}
	}
	return (ret);
}

int	s_quotes(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;
	int		ret;

	ret = SUCC;
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
		{
			ft_free_token(lst);
			printf("Signle Quotes error !!\n");
			ret = ERR;
		}
	}
	return (ret);
}

int	ft_operators(char *str, t_token **lst, int *a, int *b)
{
	char	*s;
	int		ret;

	s = NULL;
	ret = SUCC;
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
		{
			printf("& error !!\n");
			ret = SUCC;
		}
	}
	else
	{
		printf("PIPE or OR error !!\n");
		ret = ERR;
	}
	return (ret);
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
