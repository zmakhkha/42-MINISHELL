/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:55:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/25 23:51:35 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// int	o_O_o()
// {
		
// }

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
