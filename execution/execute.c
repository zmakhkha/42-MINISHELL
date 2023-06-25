/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:55:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/25 11:48:05 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_execution(t_token *list, t_env *env)
{
	char	**expanded_cmd;

	if (!list)
		return (EXIT_FAILURE);
	if (list->type == PIPE || list->type == AND || list->type == OR || \
		list->type == Empty)
		g_status = execute_logical_op(list, env);
	if (list->type == WORD)
	{
		expanded_cmd = ft_main_exp(list->str, env);
		// ft_p2darray(expanded_cmd,2);
		if (!expanded_cmd)
			return (EXIT_FAILURE);
		if (is_builtin(expanded_cmd))
			g_status = execute_builtin(expanded_cmd, env);
		else
			g_status = execute_command(expanded_cmd, env);
		ft_free_2dstr(expanded_cmd);
	}
	return (g_status);
}
