/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_re.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:08:24 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/06 17:43:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_re(t_token *list, t_env *env)
{
	int	status;

	status =  g_glob.g_status;
	if (!list)
		return (EXIT_SUCCESS);
	if (list->type == Empty)
	{
		status = execute_re(list->left, env);
		status = execute_re(list->right, env);
	}
	if (list->type == RE_IN)
		status = run_re_in(list, env);
	else if (list->type == RE_OUT)
		status = run_re_out(list, env);
	else if (list->type == APPEND)
		status = run_append(list, env);
	else
		status = EXIT_FAILURE;
	if (status == EXIT_FAILURE)
		return (status);
	return (EXIT_SUCCESS);
}
