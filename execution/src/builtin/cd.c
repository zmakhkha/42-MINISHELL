/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:42:09 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/13 04:59:59 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	ft_cd_home(t_env **env)
{
	char	*path_home;

	path_home = get_value("HOME", *env);
	if (!path_home)
	{
		ft_putstr_fd("cd: HOME not set\n", ERR);
		return (1);
	}
	if (chdir(path_home) != 0)
	{
		perror("cd");
		return (1);
	}
	change_env("PWD", path_home, env);
	return (0);
}

int	execute_cd(char **cmd, t_env **env)
{
	char	*path;
	int		res;

	if (!cmd[1])
		return (ft_cd_home(env));
	path = cmd[1];
	res = chdir(path);
	if (res == -1)
	{
		perror("cd");
		return (1);
	}
	else if (access(getcwd(NULL, 0), F_OK) != 0 && !ft_strcmp(cmd[1], "."))
	{
		ft_putendl_fd("cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory",
						ERR);
		return (1);
	}
	else if (access(getcwd(NULL, 0), F_OK) != 0 && !ft_strcmp(cmd[1], ".."))
	{
		chdir(get_value("OLDPWD",*env));
		if (res == -1)
		{
			perror("cd");
			return (1);
		}
		change_env("OLDPWD",path,env);
	}
	change_env("PWD", getcwd(NULL, 0), env);
	return (0);
}
