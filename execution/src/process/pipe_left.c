/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:42:25 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/25 04:36:17 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

void	child1_handler(t_pipex *pipex, t_token *list, t_env *env)
{
	ft_protect(close(pipex->pipefd[0]), "close", "close failed");
	ft_protect(dup2(pipex->pipefd[1], STDOUT_FILENO), "dup2", "dup2 failed");
	ft_protect(close(pipex->pipefd[1]), "close", "close failed");
	pipex->status = ft_execution(list->left, env);
	exit(pipex->status);
}
