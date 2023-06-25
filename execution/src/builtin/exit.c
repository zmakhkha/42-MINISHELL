/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:40:39 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/25 03:39:12 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

bool	check_if_all_digits(char *string)
{
	while (*string)
	{
		if (!ft_isdigit(*string))
		{
			return (false);
		}
		string++;
	}
	return (true);
}

int	execute_exit(char **list)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);

	if (list[1] == NULL)
		exit(g_status);
	else if (check_if_all_digits(list[1]))
	{
		if (list[2] != NULL)
		{
			ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
			return (1);
		}

		long exit_status = ft_atoi(list[1]);
		if (exit_status == LONG_MIN || exit_status == LONG_MAX)
		{
			ft_putstr_fd("exit: numeric argument out of range\n",
					STDERR_FILENO);
			exit(255);
		}
		exit((int)exit_status);
	}
	else
	{
		ft_putstr_fd("exit: numeric argument required\n", STDERR_FILENO);
		exit(255);
	}
	return (0);
}