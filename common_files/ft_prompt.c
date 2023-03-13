/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:14:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/13 16:37:02 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_print(char *a)
{
	write(1, a, ft_strlen(a));
}

void	ft_prompt(void)
{
	char	*str;

	while (1)
	{
		usleep(100);
		str = readline("minishell >> ");
		if (str == NULL)
		{
			printf("\n");
			break ;
		}
		if (ft_strlen(str) > 0)
		{
			ft_add_history(str);
			printf("%s\n", str);
		}
		free(str);
	}
}

int	ft_add_history(char *str)
{
	int		fd;
	ssize_t	b;

	fd = open(H_PATH, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		ft_exit("Failed to create the history file !!\n", 1);
	b = write(fd, str, ft_strlen(str));
	if (b == -1)
		ft_exit("Failed to update the history file !!\n", 1);
	b = write(fd, "\n", 1);
	if (b == -1)
		ft_exit("Failed to update the history file !!\n", 1);
	if (close(fd) == -1)
		ft_exit("Failed to close history file !!\n", 1);
	return (0);
}

// Return the user input allocated
char	*ft_read_input(char *str)
{
	return (ft_strdup(str));
}
