/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:13:41 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/30 19:41:57 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	ft_child_process(t_cmd *cmd, t_env *env)
{
	int	i;

	i = 0;
	while(cmd->args[++i])
	{
		if (cmd->args[i][0] == '\'')
			cmd->args[i] = ft_strtrim(cmd->args[i], "'");
	}
		cmd->args[i] = ft_main_exp(cmd->args[i], env);
	if (execve(cmd->path_cmd, cmd->args, cmd->env) == -1)
	{
		ft_perror(*cmd->args, CNF);
		return (127);
	}
	exit(EXIT_SUCCESS);
}
