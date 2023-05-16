/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:33:12 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/16 18:14:26 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_exit(char *c, int s)
{
	write(1, c, ft_strlen(c));
	exit(s);
}

int	ft_valid_word(char c)
{
	return (!ft_is_operator(c) \
	&& !ft_is_quote(c) && !ft_is_operator2(c) && \
	!ft_is_whitespace(c) && !ft_forbidden(c) && !ft_isdigit(c));
}

int	ft_is_valid_comm2(char c)
{
	return (!ft_is_operator4(c) \
	&& !ft_is_quote(c) && !ft_is_operator2(c));
}

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_is_operator3(char c)
{
	return (c == '<' || c == '>');
}
