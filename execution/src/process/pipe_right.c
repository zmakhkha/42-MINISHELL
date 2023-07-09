/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:25:00 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/06 18:40:58 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

void	child2_handler(t_pipex *pipex, t_token *list, t_env *env)
{
	ft_protect(close(pipex->pipefd[1]), "close", "close failed");
	ft_protect(dup2(pipex->pipefd[0], STDIN_FILENO), "dup2", "dup2 failed");
	ft_protect(close(pipex->pipefd[0]), "close", "close failed");
	pipex->status = ft_execution(list->right, &env);
	exit(pipex->status);
}
