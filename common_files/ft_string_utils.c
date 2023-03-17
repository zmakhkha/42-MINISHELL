/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:26:38 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/16 23:38:14 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	white_comm(char *str, t_token **lst, int *a, int *b)
{
	int		j;
	char	*s;

	j = *b;
	while (str[(*b)] && ft_is_valid_comm(str[*b]))
		*b += 1;
	s = ft_substr(str, *a, j - *a + 1);
	ft_token_addback(lst, ft_add_token(s, WORD));
	free(s);
	return ;
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
			s = ft_substr(str, *a + 1, *b - *a -1);
			ft_token_addback(lst, ft_add_token(s, DQ_COMM));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			ft_exit("Double Quotes error !!\n", 1);
		}
	}
	if (s)
		free(s);
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
			s = ft_substr(str, *a + 1, *b - *a -1);
			ft_token_addback(lst, ft_add_token(s, SQ_COMM));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			ft_exit("Signle Quotes error !!\n", 1);
		}
	}
	if (s)
		free(s);
}

void	ft_operators(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (ft_voperator(str + *b, '|'))
	{
		write(1, b, 1);
		if (ft_validouble(str + *b, '|'))
		{
			s = ft_substr(str, *a, *a + 2);
			ft_token_addback(lst, ft_add_token(s, OR));
			*b += 2;
		}
		else if (str[*b] == '|')
		{
			s = ft_substr(str, *a, *b + 1);
			ft_token_addback(lst, ft_add_token(s, PIPE));
			*b += 1;
		}
	}
	else if (ft_voperator(str + *b, '&'))
	{
		if (ft_validouble(str + *b, '&'))
		{
			s = ft_substr(str, *a, *b + 2);
			ft_token_addback(lst, ft_add_token(s, AND));
			*b += 2;
		}
	}
	else
	{
		ft_exit("operators error !!", 1);
	}
	if (s)
		free (s);
}

// Still to handle multiple parethetises
void	ft_prt(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && str[*b] == '(')
	{
		*b += 1;
		while (str[*b] && str[*b] != ')')
			*b += 1;
		if (str[*b] == ')')
		{
			s = ft_substr(str, *a + 1, *b - *a -1);
			ft_token_addback(lst, ft_add_token(s, SUBSHELL));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			ft_exit("Parenthesis Quotes error !!\n", 1);
		}
	}
	if (s)
		free(s);
}

// void	ft_ptr(char *str, t_token **lst, int *a, int *b)
// {
// 	int		len;
// 	char	*s;
// 	int		open;

// 	open = 0;
// 	s = NULL;
// 	len = ft_strlen(str);
// 	while (str[*b])
// 	{
// 		if (str[*b] == '(')
// 			open++;
// 		if (str[*b] == '(')
// 			open--;
// 		*b += 1;
// 	}
// }