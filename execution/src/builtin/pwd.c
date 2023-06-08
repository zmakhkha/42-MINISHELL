/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:49:51 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/05 13:17:17 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

void	execute_pwd(t_env *env)
{
	char	*path;
	(void)env;
	path = getcwd(NULL,0);
	change_env("PWD",path,env);
	puts(path);
	if (!path)
	{
		ft_putstr_fd("path not found\n", STDERR_FILENO);
		return ;
	}
	ft_putstr_fd(path, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free(path);
}
