/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:16:02 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 04:47:58 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

char	**get_path(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = ft_split(env[i] + 5, ':');
			return (paths);
		}
		i++;
	}
	ft_putendl_fd("Path env is not set", ER);
	return (NULL);
}

t_cmd	ft_init_cmd(char **args, char **env)
{
	t_cmd	cmd;

	cmd.args = args;
	cmd.name = cmd.args[0];
	cmd.env = env;
	cmd.paths = get_path(env);
	return (cmd);
}

char	*set_cmd_path(t_cmd *cmd)
{
	char	*path;
	char	*temp_path;
	int		i;

	i = 0;
	path = NULL;
	cmd->name = ft_strjoin("/", cmd->name);
	while (cmd->paths[i])
	{
		temp_path = ft_strjoin(cmd->paths[i], cmd->name);
		if (access(temp_path, X_OK | F_OK) == 0)
		{
			path = ft_strdup(temp_path);
			free(temp_path);
			free(cmd->name);
			return (path);
		}
		free(temp_path);
		temp_path = NULL;
		i++;
	}
	free(cmd->name);
	return (NULL);
}

bool	ft_check_relative_or_binary(t_cmd *cmd)
{
	if (ft_strchr(cmd->name, '/'))
		return (true);
	return (false);
}

int	execute_command(char **args, t_env *env)
{
	t_cmd	cmd;
	pid_t	pid;
	int		status;

	status = initialize_command(&cmd, args, env);
	pid = ft_protect(fork(), "fork", "Fork failed");
	if (pid == 0)
	{
		status = execute_child_process(&cmd, env);
		exit(status);
	}
	ft_signal_ignore();
	waitpid(-1, &status, 0);
	ft_signal_main();
	ft_free_2dstr(cmd.paths);
	free(cmd.path_cmd);
	ft_free_2dstr(cmd.env);
	return (status);
}
