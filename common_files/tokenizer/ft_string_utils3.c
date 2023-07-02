/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:54:38 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/17 10:54:38 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_voperator(char *str, char op)
{
	int	i;

	i = 0;
	if (str[i] && str[i + 1] && str[i + 2])
	{
		if (str[i] == op && str[i + 1] == op && str[i + 2] == op)
			return (ERR);
	}
	if (str[i] && str[i + 1])
	{
		if (str[i] == op || str[i + 1] == op)
			return (SUCC);
	}
	if (str[i])
	{
		if (str[i] == '&')
			return (ERR);
		else if (str[i] == op)
			return (SUCC);
	}
	return (0);
}

int	ft_validouble(char *str, char op)
{
	int	i;

	i = 0;
	if (str[i] && str[i + 1])
	{
		if (str[i] == op && str[i + 1] == op)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	ft_prt(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (str[*b] && (str[*b] == '(' && if_validp(str + *b) != -1))
	{
		*b += if_validp(str + *b);
		if (str[*b] == ')')
		{
			s = ft_substr(str, *a + 1, *b - *a - 1);
			if (ft_strlen(s) > 0)
				ft_token_addback(lst, ft_add_token(s, SUBSHELL));
			else
			{
				g_glob.g_status = ERR;
				return ;
			}
			*b += 1;
		}
	}
	else
		g_glob.g_status = ERR;
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
			if_validp(str + i + 1);
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

char	*ft_toktostr(t_token *src)
{
	char	*res;
	char	*tmp;
	char	*tmp2;

	res = NULL;
	while (src)
	{
		tmp = ft_strdup(src->str);
		tmp2 = res;
		res = ft_join_free(tmp2, tmp);
		// if (tmp2)
		// {
		// 	free(tmp2);
		// 	tmp2 = NULL;
		// }
		src = src->prev;
	}
	ft_free_token(&src);
	return (res);
}
