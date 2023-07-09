/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_ope.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:32:50 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 04:01:50 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_logical_op(t_token *list, t_env *env)
{
	int	status;

	status = EXIT_SUCCESS;
	if (list == NULL)
		return (EXIT_FAILURE);
	if (list->type == Empty)
	{
		status = execute_empty(list, env);
	}
	else if (list->type == PIPE)
	{
		status = execute_pipe(list, env);
	}
	else if (list->type == AND)
	{
		status = execute_and(list, env);
	}
	else if (list->type == OR)
	{
		status = execute_or(list, env);
	}
	return (status);
}
