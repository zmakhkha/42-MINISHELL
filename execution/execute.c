/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:55:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/13 03:57:57 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	execute_command(char *args, t_env *env)
{
	t_cmd	cmd;
	pid_t	pid;
	printf("this is cmd -->(%s)\n",args);
	cmd = ft_init_cmd(args, list_to_array(env));
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		g_status = ft_child_process(&cmd);
		exit(g_status);
	}
	waitpid(pid, &g_status, 0);
	return (g_status);
}

int	ft_execution(t_token *list, t_env *env)
{
	char	**splited;

	if (!list)
		return (EXIT_FAILURE);
	// if (list->type == PIPE || list->type == AND || list->type == OR)
	// {
	// 	execute_logical_op(list, env);
	// 	return ;
	// }
	if (list->type == WORD)
	{
		splited = ft_split(list->str, ' ');
		if (!splited)
			return (EXIT_FAILURE);
		if (is_builtin(splited))
			g_status = execute_builtin(splited, env);
		else
			g_status = execute_command(list->str, env);
	}
	return (g_status);
}
