/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:33:12 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/15 18:20:02 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_exit(char *c, int s)
{
	write(1, c, ft_strlen(c));
	exit(s);
}

int	ft_is_valid_comm(char c)
{
	return (!(c == '&' || c == '|' || c == '&' || c == '(' || c == ')' \
	|| c == '=' || c == '$' || c == ';') && !ft_is_operator(c) \
	&& !ft_is_quote(c) && !ft_is_operator2(c));
}

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_is_operator(char c)
{
	return (c == '|' || c == '&' || c == '(' || c == ')' || \
	c == '=' || c == '$');
}

int	ft_is_quote(char c)
{
	return (c == '\'' || c == '\"');
}
