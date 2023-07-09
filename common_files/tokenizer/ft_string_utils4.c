/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:43:14 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/07 00:53:46 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_forbidden(char *str)
{
	if (ft_strchr(str, ';') || ft_strchr(str, '\\'))
	{
		printf("unsupported character\n");
		g_glob.g_status = ERR;
		return (ERR);
	}
	else
	{
		g_glob.g_status = SUCC;
		return (SUCC);
	}
}
