/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:49:51 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/22 03:27:26 by ayel-fil         ###   ########.fr       */
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
	path = get_value("PWD", *env);
	ft_putstr_fd(path, OUT);
	ft_putstr_fd("\n", OUT);
	return (0);
}
