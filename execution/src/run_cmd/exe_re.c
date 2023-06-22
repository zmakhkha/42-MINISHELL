/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_re.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:08:24 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/22 23:36:37 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_re(t_token *list, t_env *env)
{
	// Implementation of I/O redirection
	// ...
	// Assuming the `t_token` struct has members for input/output file names
	// Return the appropriate status

	// (void)list;
	if (!list)
	{
		puts("mnaytk");
		return (1);
	}
	(void)env;
	execute_re(list->left, env);
	printf("type ------->(%d)\n", list->type);
	printf("str ------->(%s)\n", list->str);
	execute_re(list->right, env);
	return (EXIT_SUCCESS);
}