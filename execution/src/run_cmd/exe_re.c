/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_re.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:08:24 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 03:10:00 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_re(t_token *list, t_env *env)
{
	int	status;

	status = g_glob.g_status_exit;
	if (!list)
		return (EXIT_SUCCESS);
	if (list->type == Empty)
	{
		status = execute_re(list->left, env);
		if (status != 1)
			status = execute_re(list->right, env);
	}
	else if (list->type == RE_IN)
		status = run_re_in(list);
	else if (list->type == RE_OUT)
		status = run_re_out(list);
	else if (list->type == APPEND)
		status = run_append(list);
	else
		status = EXIT_FAILURE;
	return (status);
}
