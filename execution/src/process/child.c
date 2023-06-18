/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:13:41 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/18 16:13:14 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	ft_child_process(t_cmd *cmd)
{
	char	*path;

	path = ft_strdup("");
	cmd->relative_or_binary = ft_check_relative_or_binary(cmd);
	if (cmd->relative_or_binary == false)
	{
		path = set_cmd_path(cmd);
		if (!path)
			exit(EXIT_FAILURE);
	}
	else if (cmd->relative_or_binary == true)
		path = ft_strdup(cmd->name);
	if (execve(path, cmd->args, cmd->env) == -1)
	{
		ft_perror(*cmd->args,CNF); //* haday l9lawi rado l acccess
		return (127);
	}
	exit(EXIT_SUCCESS);
}
