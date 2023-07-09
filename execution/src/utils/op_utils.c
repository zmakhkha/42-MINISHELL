/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 03:57:33 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 04:01:36 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_empty(t_token *list, t_env *env)
{
	int	status;
	int	fd_in;
	int	fd_out;

	fd_in = dup(STDIN_FILENO);
	fd_out = dup(STDOUT_FILENO);
	status = execute_re(list->left, env);
	if (status != 1)
		status = ft_execution(list->right, &env);
	ft_protect(dup2(fd_in, STDIN_FILENO), "dup2", "dup2 failed");
	ft_protect(dup2(fd_out, STDOUT_FILENO), "dup2", "dup2 failed");
	return (status);
}

int	execute_and(t_token *list, t_env *env)
{
	int	status;

	if (ft_execution(list->left, &env) == EXIT_SUCCESS)
		status = ft_execution(list->right, &env);
	else
		status = 127;
	return (status);
}

int	execute_or(t_token *list, t_env *env)
{
	int	status;

	if (ft_execution(list->left, &env) != EXIT_SUCCESS)
		status = ft_execution(list->right, &env);
	else
		status = EXIT_SUCCESS;
	return (status);
}
