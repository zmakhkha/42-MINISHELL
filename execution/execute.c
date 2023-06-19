/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:55:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/16 03:36:59 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_execution(t_token *list, t_env *env)
{
	char	**splited;

	if (!list)
		return (EXIT_FAILURE);
	if (list->type == PIPE || list->type == AND || list->type == OR)
			g_status = execute_logical_op(list, env);
	if (list->type == WORD)
	{
		splited = ft_split(list->str, ' ');
		if (!splited)
			return (EXIT_FAILURE);
		if (is_builtin(splited))
			g_status = execute_builtin(splited, env);
		else
			g_status = execute_command(list->str, env);
	}
	return (g_status);
}
