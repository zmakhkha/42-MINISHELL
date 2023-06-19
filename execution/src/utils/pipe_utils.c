/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:42:25 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/18 15:49:17 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

void	child1_handler(t_pipex *pipex, t_token *list, t_env *env)
{
	close(pipex->pipefd[0]);
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
	{
		ft_perror("dup2", " ");
		exit(EXIT_FAILURE);
	}
	close(pipex->pipefd[1]);
	pipex->status = ft_execution(list->left, env);
	exit(pipex->status);
}

void	child2_handler(t_pipex *pipex, t_token *list, t_env *env)
{
	close(pipex->pipefd[1]);
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
	{
		ft_perror("dup2", " ");
		exit(EXIT_FAILURE);
	}
	close(pipex->pipefd[0]);
	pipex->status = ft_execution(list->right, env);
	exit(pipex->status);
}