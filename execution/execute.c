/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:55:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/05 15:15:05 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	execute_command(t_token *list,t_env env)
{
	t_pipex	px;

	px = ft_init_pipex(av, env);
	if (px.proccess.child_1 == 0)
		ft_child_1_process(av[2], px);
	px.proccess.child_2 = ft_protect(fork(), NULL, "child_2");
	if (px.proccess.child_2 == 0)
		ft_child_2_process(av[3], px);
}

void	ft_execution(t_token *list, t_env *env)
{
	if (!list)
	{
		printf("Error: Command not found\n");
		return ;
	}

	// if (list->type == PIPE || list->type == AND || list->type == OR)
	// {
	// 	execute_logical_op(list, env);
	// 	return ;
	// }

	if (list->type == WORD)
	{
		char **splited;
		splited = ft_split(list->str,' ');
		ft_p2darray(splited,1);
		if(is_builtin(list->str))
			execute_builtin(splited,env);
		else
		{
			execute_command(list, env);
			return ;
		}
	}
}