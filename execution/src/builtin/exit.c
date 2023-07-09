/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:40:39 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 02:37:18 by ayel-fil         ###   ########.fr       */
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
	long	exit_status;

	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (list[1] == NULL)
		exit(g_glob.g_status_exit);
	else if (check_if_all_digits(list[1]))
	{
		if (list[2] != NULL)
			return (ft_putendl_fd(EXIT_ERR, STDERR_FILENO), 1);
		exit_status = ft_atoi(list[1]);
		if (exit_status == LONG_MIN || exit_status == LONG_MAX)
		{
			ft_putendl_fd("exit: numeric argument out of range", STDERR_FILENO);
			exit(255);
		}
		exit(exit_status % 255);
	}
	else
	{
		ft_putendl_fd("exit: numeric argument required", STDERR_FILENO);
		exit(255);
	}
	return (0);
}
