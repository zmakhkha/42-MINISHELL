/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:24:48 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/16 15:06:34 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

void	ft_error(char *msg, char *cmd, int exit_status)
{
	if (!cmd)
		cmd = " ";
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(cmd, 2);
	exit(exit_status);
}

int	ft_protect(int fd, char *str, char *msg)
{
	if (!ft_strcmp(str, "execve") && fd == -1)
		ft_error(CNF, str, 1);
	if (fd == -1 && !str)
	{
		perror(msg);
		exit(fd);
	}
	return (fd);
}

void	ft_perror(char *err_msg1, char *err_msg2)
{
	ft_putstr_fd("minish: ", ER);
	ft_putstr_fd(err_msg1, ER);
	ft_putstr_fd(": ", ER);
	ft_putendl_fd(err_msg2, ER);
}
