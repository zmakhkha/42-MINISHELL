/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:43:14 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/26 14:15:39 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_forbidden(char *str)
{
	if (ft_strchr(str, ';') || ft_strchr(str, '\\'))
	{
		printf("unsupported character\n");
		g_status = ERR;
		return (ERR);
	}
	else
	{
		g_status = SUCC;
		return (SUCC);
	}
}
