/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_re.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:08:24 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/23 04:37:11 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	run_re_in(t_token *list, t_env *env)
{
	int	fd;
	int	status;

	status = EXIT_SUCCESS;
	fd = ft_protect(open(list->left->str, O_RDONLY),"open","Error opening input file");
	dup2(fd, STDIN_FILENO);
	close(fd);
	status = execute_command(list->right, env);
	return (status);
}

int	run_re_out(t_token *list, t_env *env)
{
	int	fd;
	int	status;

	status = EXIT_SUCCESS;
	fd = open(list->left->str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error opening output file");
		return (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	status = ft_execution(list->right, env);
	return (status);
}

int	run_append(t_token *list, t_env *env)
{
	int	fd;
	int	status;

	fd = open(list->left->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("Error opening append file");
		return (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	status = ft_execution(list->right, env);
	return (status);
}

int	execute_re(t_token *list, t_env *env)
{
	int	status;

	if (!list->right || !list->right->str)
		return (EXIT_FAILURE);
	status = EXIT_FAILURE;
	if (list->left->type == RE_IN)
		status = run_re_in(list, env);
	else if (list->left->type == RE_OUT)
		status = run_re_out(list, env);
	else if (list->left->type == APPEND)
		status = run_append(list, env);
	return (status);
}
