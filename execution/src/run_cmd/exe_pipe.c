/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:49:04 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/19 07:14:13 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_pipe(t_token *list, t_env *env)
{
	t_pipex	pipex;

	if (pipe(pipex.pipefd) == -1)
	{
		ft_perror("pipe", " ");
		return (EXIT_FAILURE);
	}
	pipex.pid_1 = fork();
	if (pipex.pid_1 == -1)
	{
		ft_perror("fork", " ");
		close(pipex.pipefd[0]);
		close(pipex.pipefd[1]);
		return (EXIT_FAILURE);
	}
	else if (pipex.pid_1 == 0)
	{
		child1_handler(&pipex, list, env);
	}
	pipex.pid_2 = fork();
	if (pipex.pid_2 == -1)
	{
		ft_perror("fork", " ");
		close(pipex.pipefd[0]);
		close(pipex.pipefd[1]);
		return (EXIT_FAILURE);
	}
	else if (pipex.pid_2 == 0)
	{
		child2_handler(&pipex, list, env);
	}
	pipex.status = ft_exit_pipe(&pipex);
return (pipex.status);
}