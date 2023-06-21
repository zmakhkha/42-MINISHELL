/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:42:09 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/21 06:18:35 by ayel-fil         ###   ########.fr       */
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
	
	if (!cmd[1])
		return (ft_cd_home(env));
	path = cmd[1];
	if (chdir(path )== -1)
	{
		perror("cd");
		return (1);
	}
	else if (access(getcwd(NULL, 0), F_OK) != 0 && !ft_strcmp(cmd[1], "."))
	{
		ft_putendl_fd(CD_ER,ERR);
		return (1);
	}
	else if (access(getcwd(NULL, 0), F_OK) != 0 && !ft_strcmp(cmd[1], ".."))
	{
		if (chdir(get_value("OLDPWD", *env)) == -1)
		{
			perror("cd");
			return (1);
		}
		change_env("OLDPWD", path, env);
	}
	change_env("PWD", getcwd(NULL, 0), env);
	return (0);
}
