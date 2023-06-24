/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/24 13:50:16 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void ft_main_handler(int signal)
{
    if (signal == SIGINT)
    {
        write(1, "\nminishell $ ", 13);
    }
    else if (signal == SIGQUIT)
    {
    }
    else if (signal == 50)
    {
        write(1, "exit", 4);
		exit(0);
    }
}

void ft_signal_main()
{
    struct sigaction signal;
	// void	(*pr)(int , int);  

    signal.sa_handler = ft_main_handler;
    sigemptyset(&signal.sa_mask);
    signal.sa_flags = SA_RESTART;

    sigaction(SIGINT, &signal, NULL);
    sigaction(SIGTERM, &signal, NULL);
    sigaction(SIGQUIT, &signal, NULL);
}

int	main(int ac, char **av, char **env)
{
	ft_signal_main();
	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	ft_prompt(env);
	return (0);
}
