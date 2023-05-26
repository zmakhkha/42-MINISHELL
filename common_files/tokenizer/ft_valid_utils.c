/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:27:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/26 15:34:14 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_is_operator(char c)
{
	return (c == '|' || c == '&' || c == '(' || c == ')' || \
	c == '=' || c == '$' || c == '*' || c == ';');
}

int	ft_is_moperator(char c)
{
	return (c == '|' || c == '&');
}

int	ft_is_operator4(char c)
{
	return (c == '|' || c == '&' || \
	c == '=' || c == '$');
}

int	ft_is_operator2(char c)
{
	return (c == '<' || c == '>');
}

int	ft_is_quote(char c)
{
	return (c == '\'' || c == '\"');
}
