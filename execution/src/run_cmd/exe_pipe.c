/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:49:04 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/17 02:30:42 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_pipe(t_token *list, t_env *env)
{
	int		pipefd[2];
	int		status;
	pid_t	pid;

	status = 0;
	if (pipe(pipefd) == -1)
	{
		ft_perror("pipe", " ");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_perror("fork", " ");
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		{
			ft_perror("dup2", " ");
			exit(EXIT_FAILURE);
		}
		close(pipefd[1]);
		close(STDOUT_FILENO);
		exit(status);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_perror("fork", " ");
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
		{
			ft_perror("dup2", " ");
			return (EXIT_FAILURE);
		}
		close(pipefd[0]);
		status = ft_execution(list->right, env);
		exit(status);
	}
	waitpid(pid, NULL, 0);
	return (status);
}
