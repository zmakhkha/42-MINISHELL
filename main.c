/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/05 18:03:13 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_global	g_glob = {.g_ctrl_c = 0, .g_ctrl_s = 0, .g_status = 0};
// void	l(void)
// {
// 	system("leaks minishell");
// }

// void	detect(void	*res)
// {
// 		// puts("\n");
// 		printf("\nHADA: %p,\n", res);
// 		// puts("\n");
// }

int	main(int ac, char **av, char **env)
{
	rl_catch_signals = 0;
	rl_initialize();
	ft_signal_main();
	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	ft_prompt(env);
	return (0);
}
