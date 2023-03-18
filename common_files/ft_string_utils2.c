/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:58:29 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/18 13:26:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_space(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	while (str[(*b)] && ft_is_whitespace(str[*b]))
		*b += 1;
	s = ft_substr(str, *a, *b - *a);
	ft_token_addback(lst, ft_add_token(s, SPACE));
}

void	ft_operators2(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (ft_voperator(str + *b, '>') || ft_voperator(str + *b, '<'))
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
		ft_exit("operators 2 error !!", 1);
}

void	ft_operators3(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	(void)a;
	s = NULL;
	if (ft_voperator(str + *b, '<'))
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
		ft_exit("Operators 3 Error !!", 1);
}

int	if_validp(char *str)
{
	int	open;
	int	i;

	i = 0;
	open = 1;
	while (str[++i])
	{
		if (str[i] == '(')
		{
			open++;
			if_validp(str + i +1);
		}
		if (str[i] == ')')
		{	
			open--;
			if (!open)
				return (i);
		}
	}
	if (!open)
		return (i);
	return (-1);
}

void	ft_prt(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && (str[*b] == '(' && if_validp(str + *b) != -1))
	{
		*b += if_validp(str + *b);
		if (str[*b] == ')')
		{
			s = ft_substr(str, *a + 1, *b - *a -1);
			ft_token_addback(lst, ft_add_token(s, SUBSHELL));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			ft_exit("SUBSHELL Quotes error !!\n", 1);
		}
	}
	else
		ft_exit("SUBSHELL errors !!\n", 1);
}
