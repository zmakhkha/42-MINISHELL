/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:49:04 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/22 23:09:40 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_pipe(t_token *list, t_env *env)
{
	t_pipex pipex;

	ft_protect(pipe(pipex.pipefd), "Pipe", "Pipe failed");
	pipex.pid_1 = ft_protect(fork(), "fork", "Fork failed");
	if (pipex.pid_1 == 0)
		child1_handler(&pipex, list, env);
	pipex.pid_2 = ft_protect(fork(), "fork", "Fork failed");
	if (pipex.pid_2 == 0)
		child2_handler(&pipex, list, env);
	pipex.status = ft_exit_pipe(&pipex);
	return (pipex.status);
}