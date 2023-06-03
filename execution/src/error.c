/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:24:48 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/02 16:27:42 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_error(char *msg, char *cmd)
{
	if (!cmd)
		cmd = " ";
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(cmd, 2);
	return ;
}

int	ft_protect(int fd, char *str, char *msg)
{
	if (!ft_strcmp(msg, "execve") && fd == -1)
		ft_error("command not found", str);
	if (fd == -1 && !str)
	{
		perror(msg);
		exit(1);
	}
	return (fd);
}