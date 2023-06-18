/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:24:48 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/18 15:55:04 by ayel-fil         ###   ########.fr       */
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
	ft_putstr_fd(err_msg2, ER);
}
int	ft_exit_pipe(t_pipex *px)
{
	close(px->pipefd[1]);
	close(px->pipefd[0]);
	// waitpid(px->pid_1, &px->status, 0);
    // waitpid(px->pid_2, &px->status, 0);
	// wait(NULL);
	// wait(NULL);	
	while (waitpid(-1, &px->status, 0) != -1)
		;
	return (px->status);
}
