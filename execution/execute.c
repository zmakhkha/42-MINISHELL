/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:55:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/03 04:09:57 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_execution(t_token *list, t_env *env)
{
	if (!list)
	{
		return (0);
	}
	if (list->type == WORD)
	{
		if (is_builtin(list->str))
		{
			execute_builtin(list, env);
			return (0);
		}
	}
	printf("Error: command not found\n");
	return (1);
}