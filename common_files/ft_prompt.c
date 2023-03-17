/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:14:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/17 16:43:15 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_print(char *a)
{
	write(1, a, ft_strlen(a));
}

// Add a command history
void	ft_prompt(void)
{
	char	*str;
	t_token	*t;
	t_token	*tmp;

	while (1)
	{
		usleep(100);
		str = readline("minishell >> ");
		if (str == NULL)
			break ;
		printf("%s\n", str);
		ft_add_history(str);
		t = ft_strtok(str);
		tmp = t;
		while (t)
		{
			ft_pr(t->type);
			printf("\n");
			t = t->prev;
		}
		free (str);
		ft_free_token(&tmp);
	}
}

// Add a file history
int	ft_add_history(char *str)
{
	int		fd;
	ssize_t	b;

	add_history(str);
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
