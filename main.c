/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/24 09:57:15 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	l(void)
// {
// 	system("leaks minishell");
// }

void	ft_handle(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\nminishell $", 12);
	}
	else if (signal == EOF)
		{
			write(1, "exit", 4);
		}
	else if (signal == SIGQUIT)
	{
	}
}

void	ft_handle_child(int signal)
{
	if (signal == SIGINT || signal == SIGQUIT)
	{
		exit(0);
	}
	else if (signal == EOF)
		write(1, "exit", 4);

}

void	detect(void	*res)
{
		// puts("\n");
		printf("\nHADA: %p,\n", res);
		// puts("\n");
}
int	main(int ac, char **av, char **env)
{
	struct sigaction	signal;

	signal.sa_handler = ft_handle;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	
	sigaction(SIGINT, &signal, NULL);
	sigaction(SIGQUIT, &signal, NULL);
	sigaction(SIGTERM, &signal, NULL);

	
	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	ft_prompt(env);
	return (0);
}
