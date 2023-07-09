/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 04:03:55 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 06:23:07 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	initialize_command(t_cmd *cmd, char **args, t_env *env)
{
	*cmd = ft_init_cmd(args, list_to_array(env));
	cmd->relative_or_binary = ft_check_relative_or_binary(cmd);
	if (cmd->relative_or_binary == false)
	{
		if (!cmd->paths)
			return (1);
		cmd->path_cmd = set_cmd_path(cmd);
		if (!cmd->path_cmd)
		{
			ft_error(CNF, args[0], 1);
			return (127);
		}
	}
	else if (cmd->relative_or_binary == true)
		cmd->path_cmd = ft_strdup(cmd->name);
	return (0);
}

int	execute_child_process(t_cmd *cmd, t_env *env)
{
	int	status;

	status = ft_child_process(cmd, env);
	ft_free_2dstr(cmd->paths);
	free(cmd->path_cmd);
	ft_free_2dstr(cmd->env);
	return (status);
}
