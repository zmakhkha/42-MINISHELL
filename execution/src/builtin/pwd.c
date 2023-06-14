/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:49:51 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/14 09:38:19 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_pwd(t_env **env)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{
		ft_putstr_fd("path not found\n", STDERR_FILENO);
		return (1);
	}
	change_env("PWD", path, env);
	path = get_value("PWD", *env);
	ft_putstr_fd(path, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
} 
