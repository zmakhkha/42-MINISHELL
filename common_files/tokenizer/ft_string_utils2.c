/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:58:29 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/25 11:45:11 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_space_(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	while (str[(*b)] && ft_is_whitespace_(str[*b]))
		*b += 1;
	s = ft_substr(str, *a, *b - *a);
	ft_token_addback(lst, ft_add_token(s, SPACE));
}

void	ft_digits(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	while (str[(*b)] && ft_isdigit(str[*b]))
		*b += 1;
	s = ft_substr(str, *a, *b - *a);
	ft_token_addback(lst, ft_add_token(s, DIGITE));
}

int	ft_operators2(char *str, t_token **lst, int *a, int *b)
{
	char	*s;
	int		ret;

	ret = SUCC;
	s = NULL;
	if (ft_voperator(str + *b, '>') == SUCC)
	{
		if (ft_validouble(str + *a, '>'))
		{	
			s = ft_substr(str, *a, 2);
			ft_token_addback(lst, ft_add_token(s, APPEND));
			*b += 2;
		}
		else if (str[*b] == '>')
		{
			s = ft_substr(str, *a, 1);
			ft_token_addback(lst, ft_add_token(s, RE_OUT));
			*b += 1;
		}
	}
	else
		g_status = ERR;
	return (ret);
}

int	ft_operators3(char *str, t_token **lst, int *a, int *b)
{
	char	*s;	
	int		ret;

	ret = SUCC;
	(void)a;
	s = NULL;
	if (ft_voperator(str + *b, '<') == SUCC)
	{
		if (ft_validouble(str + *b, '<'))
		{	
			s = ft_substr(str, *b, 2);
			ft_token_addback(lst, ft_add_token(s, HDOC));
			*b += 2;
		}
		else if (str[*b] == '<')
		{
			s = ft_substr(str, *b, 1);
			ft_token_addback(lst, ft_add_token(s, RE_IN));
			*b += 1;
		}
	}
	else
		g_status = ERR;
	return (ret);
}
