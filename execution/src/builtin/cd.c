/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:42:09 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/05 13:12:12 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

void	cd_home(t_env *env, char *old_pwd)
{
	char	*path;

	path = get_key("HOME", env);
	if (!path)
	{
		ft_putstr_fd("cd: HOME not set\n", ER);
		return ;
	}
	chdir(path);
	change_env("PWD", path, env);
	change_env("OLDPWD", old_pwd, env);
}

void	execute_cd(char **cmd, t_env *env)
{
	char	*path;
	int		res;
	char	*old_pwd;

	old_pwd = getcwd(NULL, 0);
	if (!cmd[1])
		return (cd_home(env,old_pwd));
	path = cmd[1];
	res = chdir(path);
	if (res == -1)
		perror("cd");
	change_env("PWD", path, env);
	// if (!access(getenv("PWD"), F_OK) && !ft_strcmp(cmd[1], "."))
	// {
	// 	ft_putendl_fd("cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory",
	// 					ER);
	// 	return ;
	// }
}
