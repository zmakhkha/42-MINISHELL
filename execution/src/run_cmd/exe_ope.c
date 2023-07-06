/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_ope.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:32:50 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/06 18:42:07 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_logical_op(t_token *list, t_env *env)
{
	int	status;
	int	fd_in;
	int	fd_out;

	status =  g_glob.g_status;
	if (list == NULL)
		return (EXIT_FAILURE);
	if (list->type == Empty)
	{
		fd_in = dup(STDIN_FILENO);
		fd_out = dup(STDOUT_FILENO);
		status = execute_re(list->left, env);
		status = ft_execution(list->right, &env);
		ft_protect(dup2(fd_in, STDIN_FILENO), "dup2", "dup2 failed");
		ft_protect(dup2(fd_out, STDOUT_FILENO), "dup2", "dup2 failed");
	}
	if (list->type == PIPE)
		status = execute_pipe(list, env);
	else if (list->type == AND)
	{
		if (ft_execution(list->left, &env) == EXIT_SUCCESS)
			status = ft_execution(list->right, &env);
		else
			status = EXIT_FAILURE;
	}
	else if (list->type == OR)
	{
		if (ft_execution(list->left, &env) != EXIT_SUCCESS)
			status = ft_execution(list->right, &env);
		else
			status = EXIT_SUCCESS;
	}
	return (status);
}
