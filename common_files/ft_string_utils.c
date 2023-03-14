/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:26:38 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/14 20:19:02 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	white_comm(char *str, t_token **lst, int *a, int *b)
{
	int	i;
	int	j;

	i = *a;
	j = *b;
	while (str[(j)] && ft_is_valid_comm(str[j]))
		j++;
	ft_token_addback(lst, ft_add_token(ft_substr(str, i, j - i + 1), COMMAND));
	*b = j;
	return ;
}

void	d_quotes(char *str, t_token **lst, int *a, int *b)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	i = *a;
	j = *b;
	if (str[j] && str[j] == '"')
	{
		j++;
		while (str[j] && str[j] != '"')
			j++;
		if (str[j] == '"')
		{
			ft_token_addback(lst, ft_add_token \
			(ft_substr(str, i + 1, j - i), DQ_COMM));
			j++;
		}
		else if (j == len)
		{
			ft_free_token(lst);
			ft_exit("Double Quotes error !!\n", 1);
		}
	}
	*b = j;
}

void	s_quotes(char *str, t_token **lst, int *a, int *b)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	i = *a;
	j = *b;
	if (str[j] && str[j] == '\'')
	{
		j++;
		while (str[j] && str[j] != '\'')
			j++;
		if (str[j] == '\'')
		{
			ft_token_addback(lst, ft_add_token \
			(ft_substr(str, i + 1, j - i), SQ_COMM));
			j++;
		}
		else if (j == len)
		{
			ft_free_token(lst);
			ft_exit("Signle Quotes error !!\n", 1);
		}
	}
	*b = j;
}

void	ft_operators(char *str, t_token **lst, int *a, int *b)
{
	int	i;
	int	j;
	int	len;

	i = *a;
	len = ft_strlen(str);
	j = *b;
	if (str[j] && str[j + 1] && str[j] == '|' && str[j + 1] == '|')
	{
		ft_token_addback(lst, ft_add_token(ft_substr(str, i, i + 2), OR));
		j += 2;
	}
	else if (str[j] && str[j + 1] && str[j] == '&' && str[j + 1] == '&')
	{
		ft_token_addback(lst, ft_add_token(ft_substr(str, i, j + 2), AND));
		j += 2;
	}
	else if (str[j] && str[j] == '|')
	{
		ft_token_addback(lst, ft_add_token(ft_substr(str, i, j + 1), PIPE));
		j++;
	}
	*b = j;
}

void	ft_prt(char *str, t_token **lst, int *a, int *b)
{
	int	i;
	int	j;
	int	len;

	i = *a;
	j = *b;
	len = ft_strlen(str);
	if (str[j] == '(')
	{
		while (j < len && str[j] != ')')
			j++;
		if (str[j] == ')')
		{
			ft_token_addback(lst, ft_add_token \
			(ft_substr(str, i + 1, j - i), SUBSHELL));
			j++;
		}
		else if (j == len)
		{
			ft_free_token(lst);
			ft_exit("parenthesis Error !!\n", 1);
		}
	}
	*b = j;
}
