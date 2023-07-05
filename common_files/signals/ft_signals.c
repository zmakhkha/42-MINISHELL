/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:45:43 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/05 11:08:24 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_child_handler(int signal)
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

void	ft_main_handler(int signal)
{
	rl_catch_signals = 0;
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_signal_child(void)
{
	struct sigaction	signal;

	signal.sa_handler = (void (*)(int))ft_child_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_handler = ft_child_handler;
	sigaction(SIGINT, &signal, NULL);
	sigaction(SIGTERM, &signal, NULL);
	sigaction(SIGQUIT, &signal, NULL);
}

void	ft_signal_main(void)
{
	struct sigaction	signal;

	signal.sa_handler = (void (*)(int))ft_main_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	sigaction(SIGINT, &signal, NULL);
	sigaction(SIGTERM, &signal, NULL);
	sigaction(SIGQUIT, &signal, NULL);
}

void	ft_signal_ignore(void)
{
	struct sigaction	signal;

	signal.sa_handler = SIG_IGN;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGINT, &signal, NULL);
}
