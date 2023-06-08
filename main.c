/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/02 16:18:57 by ayel-fil         ###   ########.fr       */
=======
/*   Updated: 2023/05/30 18:31:28 by zmakhkha         ###   ########.fr       */
>>>>>>> Implemented heredoc logic
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

<<<<<<< HEAD
// void	l(void)
// {
// 	system("leaks minishell");
// }

int	main(int ac, char **av, char **env)
=======
int	main(void)
>>>>>>> Implemented heredoc logic
{
	if (ac != 1 || av[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	ft_prompt(env);
	return (0);
}
