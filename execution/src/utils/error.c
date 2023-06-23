/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:24:48 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/23 17:04:36 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	ft_error(char *msg, char *cmd, int exit_status)
{

	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	return (exit_status);
}

int	ft_protect(int return_value, char *str, char *msg)
{
	if (return_value == -1)
	{
		ft_perror(str,msg);
		exit(EXIT_FAILURE);
	}
	return (return_value);
}

void	ft_perror(char *err_msg1, char *err_msg2)
{
	ft_putstr_fd("minish: ", ER);
	ft_putstr_fd(err_msg1, ER);
	ft_putstr_fd(": ", ER);
	ft_putendl_fd(err_msg2, ER);
}
int	ft_exit_pipe(t_pipex *px)
{
	close(px->pipefd[0]);
	close(px->pipefd[1]);
	waitpid(-1, &px->status, 0);
	waitpid(-1, &px->status, 0);
	return (px->status);
}
