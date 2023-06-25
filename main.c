/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/25 10:53:20 by zmakhkha         ###   ########.fr       */
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

void ft_child_handler(int signal)
{
    if (getpid() != getppid())
    {
        if (signal == SIGINT || signal == SIGTERM)
        {
            rl_replace_line("", 0);
            rl_on_new_line();
            rl_redisplay();
            exit(0);
        }
    }
}

void ft_main_handler(int signal)
{
    rl_catch_signals = 0;
    if (signal == SIGINT)
    {
        write(1, "\n", 1);
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
    else if (signal == SIGTERM)
    {
    }
}

void ft_signal_child()
{
    struct sigaction signal;

    signal.sa_handler = (void (*)(int))ft_child_handler;
    sigemptyset(&signal.sa_mask);
    signal.sa_handler = ft_child_handler;

    sigaction(SIGINT, &signal, NULL);
    sigaction(SIGTERM, &signal, NULL);
    sigaction(SIGQUIT, &signal, NULL);
}

void ft_signal_main()
{
    int                 count;
    struct sigaction    signal;

    count = 0;
    signal.sa_handler = (void (*)(int))ft_main_handler;
    sigemptyset(&signal.sa_mask);
    signal.sa_flags = SA_RESTART;

    sigaction(SIGINT, &signal, NULL);
    sigaction(SIGTERM, &signal, NULL);
    sigaction(SIGQUIT, &signal, NULL);
}

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
