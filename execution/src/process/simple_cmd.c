/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:13:41 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/02 17:19:06 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	ft_child_process(t_cmd *cmd, t_env *env)
{
	// int	i;

	(void)env;
	// i = 0;
	if (execve(cmd->path_cmd, cmd->args, cmd->env) == -1)
	{
		ft_perror(*cmd->args, CNF);
		return (127);
	}
	exit(EXIT_SUCCESS);
}
