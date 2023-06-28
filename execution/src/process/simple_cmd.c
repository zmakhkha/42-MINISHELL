/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:13:41 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/28 05:36:24 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	ft_child_process(t_cmd *cmd)
{
	int	i;

	i = 0;
	while(cmd->args[++i])
		cmd->args[i] = ft_strtrim(cmd->args[i], "'");
	if (execve(cmd->path_cmd, cmd->args, cmd->env) == -1)
	{
		ft_perror(*cmd->args, CNF);
		return (127);
	}
	exit(EXIT_SUCCESS);
}
