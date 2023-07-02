/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:47:50 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/01 15:55:29 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

static int	is_flag_n(char *flag)
{
	int	i;

	i = 0;
	if (!ft_strcmp(flag, "-n"))
		return (1);
	if (flag[0] != '-')
		return (0);
	i++;
	while (flag && flag[i])
	{
		if (flag[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	echo_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
	{
		ft_putstr(args[i]);
		if (args[i + 1])
			ft_putchar(' ');
		i++;
	}
}

int	execute_echo(char **cmd)
{
	int	new_line;
	int	i;

	new_line = 1;
	i = 1;
	if (cmd[i] == NULL)
	{
		ft_putstr("\n");
		return (g_glob.g_status);
	}
	while (cmd[i] && is_flag_n(cmd[i]))
	{
		new_line = 0;
		i++;
	}
	echo_args(cmd + i);
	if (new_line == 1)
		ft_putstr("\n");
	if (cmd[i] && !ft_strcmp(cmd[i], "?"))
	{
		ft_putnbr(g_glob.g_status);
		ft_putstr("\n");
	}
	return (g_glob.g_status);
}
