/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:55:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/06 15:44:52 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	execute_command(char *args, t_env *env)
{
	t_cmd	cmd;
	pid_t	pid;
	char	*path;

	cmd = ft_init_cmd(args, list_to_array(env));
	pid = ft_protect(fork(), "fork", 0, NULL);
	if (pid == 0)
	{
		cmd.relative_or_binary = ft_check_relative_or_binary(cmd);
		if (cmd.relative_or_binary == false)
			path = set_cmd_path(cmd);
		else if (cmd.relative_or_binary == true)
			path = cmd.name;
		ft_protect(execve(path, cmd.args, cmd.env), "execve", EXECVE,
				cmd.name);
		return ;
	}
	waitpid(pid, &g_status, 0);
}

void	ft_execution(t_token *list, t_env *env)
{
	char	**splited;

	if (!list)
	{
		printf("Error: Command not found\n");
		return ;
	}
	// if (list->type == PIPE || list->type == AND || list->type == OR)
	// {
	// 	execute_logical_op(list, env);
	// 	return ;
	// }
	if (list->type == WORD)
	{
		splited = ft_split(list->str, ' ');
		if (is_builtin(list->str))
			execute_builtin(splited, env);
		else
		{
			execute_command(list->str, env);
			return ;
		}
	}
}
