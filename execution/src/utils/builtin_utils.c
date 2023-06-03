/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:20:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/03 03:49:08 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

bool	is_builtin(char *command)
{
	if (!ft_strcmpl(command, "echo") ||
		!ft_strcmp(command, "cd") ||
		!ft_strcmpl(command, "pwd") ||
		!ft_strcmp(command, "export") ||
		!ft_strcmp(command, "unset") ||
		!ft_strcmpl(command, "env") ||
		!ft_strcmp(command, "exit"))
	{
		return (true);
	}
	return (false);
}

void	execute_builtin(t_token *list, t_env *env)
{
	// if (!ft_strcmpl(list->str, "echo"))
	// 	execute_echo(list);
	(void)env;
 if (!ft_strcmp(list->str, "cd"))
	execute_cd(list);
	else if (!ft_strcmpl(list->str, "pwd"))
		execute_pwd();
	// else if (!ft_strcmp(list->str, "export"))
	// 	execute_export(list->left, env);
	// else if (!ft_strcmp(list->str, "unset"))
	// 	execute_unset(list->left, env);
	// else if (!ft_strcmpl(list->str, "env"))
	// 	execute_env(env);
	// else if (!ft_strcmp(list->str, "exit"))
	// 	execute_exit();
}