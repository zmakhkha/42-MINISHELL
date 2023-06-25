/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_re.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:08:24 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/23 04:41:25 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_re(t_token *list, t_env *env)
{
	int	status;

	if (!list->right || !list->right->str)
		return (EXIT_FAILURE);
	status = EXIT_FAILURE;
	if (list->left->type == RE_IN)
		status = run_re_in(list, env);
	else if (list->left->type == RE_OUT)
		status = run_re_out(list, env);
	else if (list->left->type == APPEND)
		status = run_append(list, env);
	return (status);
}
