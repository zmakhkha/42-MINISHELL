/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:49:51 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/24 12:56:18 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_pwd(t_env **env)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{
		path = get_value("PWD", *env);
		ft_putstr_fd(path, OUT);
		ft_putstr_fd("\n", OUT);
		return (0);
	}
	path = get_value("PWD", *env);
	ft_putstr_fd(path, OUT);
	ft_putstr_fd("\n", OUT);
	return (0);
}
