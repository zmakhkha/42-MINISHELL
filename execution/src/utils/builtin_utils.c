/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:20:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/13 05:07:02 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

bool	is_builtin(char **command)
{
	if (!ft_strcmpl(command[0], "echo") ||
		!ft_strcmp(command[0], "cd") ||
		!ft_strcmpl(command[0], "pwd") ||
		!ft_strcmp(command[0], "export") ||
		!ft_strcmp(command[0], "unset") ||
		!ft_strcmpl(command[0], "env") ||
		!ft_strcmp(command[0], "exit"))
	{
		return (true);
	}
	return (false);
}

int	execute_builtin(char **list, t_env *env)
{
	if (list)
	{
		if (!ft_strcmpl(list[0], "echo"))
			return (execute_echo(list));
		else if (!ft_strcmp(list[0], "cd"))
			return (execute_cd(list, &env));
		else if (!ft_strcmpl(list[0], "pwd"))
			return (execute_pwd(&env));
		else if (!ft_strcmp(list[0], "export"))
			execute_export(list, &env);
		// else if (ft_strcmp(list->str, "unset"))
		// 	execute_unset(list, env);
		else if (!ft_strcmpl(list[0], "env"))
			return (execute_env(&env));
		// else if (!ft_strcmp(list->str, "exit"))
		// 	execute_exit(list);
	}
	return (EXIT_FAILURE);
}
