/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:16:02 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/06 14:37:14 by ayel-fil         ###   ########.fr       */
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
	ft_error("Path env is not set", "");
	return (0);
}

t_cmd	ft_init_cmd(char *args, char **env)
{
	t_cmd	cmd;

	cmd.args = ft_split(args, ' ');
	cmd.name = cmd.args[0];
	cmd.env = env;
	cmd.paths = get_path(env);
	return (cmd);
}

char	*set_cmd_path(t_cmd cmd)
{
	char	*path;
	int		i;

	i = 0;
	cmd.name = ft_strjoin("/", cmd.name);
	while (cmd.paths[i])
	{
		path = ft_strjoin(cmd.paths[i], cmd.name);
		if (access(path, X_OK) == 0)
			return (free(cmd.name), path);
		free(path);
		i++;
	}
	free(cmd.name);
	return (NULL);
}

bool	ft_check_relative_or_binary(t_cmd cmd)
{
	if (ft_strchr(cmd.name, '/'))
		return (true);
	return (false);
}
