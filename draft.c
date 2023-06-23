/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:02:26 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/22 17:34:20 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libc.h>
#include "header.h"
#include <fcntl.h>

// char	*ft_heredoc(char *del)
// {
// 	char	*hdoc;
// 	char	*star;

// 	star = NULL;
// 	hdoc = (char *)ft_calloc(1, 1);
// 	while (1)
// 	{
// 		star = readline("> ");
// 		if (star == NULL || !ft_strcmp(del, star))
// 			break ;
// 		else
// 			hdoc = ft_join_free(ft_join_free(hdoc, star), "\n");
// 		free(star);
// 	}
// 	return (hdoc);
// }

// char	*ft_hdoc_tofd(char *str)
// {
// 	int		fd;
// 	char	*path;
// 	char	*full_path;
// 	ssize_t	b;

// 	path = ft_join_free("HDOC", "");
// 	full_path = ft_join_free(H_DOCP, path);
// 	while (access(full_path, F_OK) == 0)
// 		full_path = ft_join_free(full_path, "_1");
// 	fd = open(full_path, O_WRONLY | O_APPEND | O_CREAT, 0644);
// 	if (fd == -1)
// 		ft_exit("Failed to create the tmp heredoc file !!\n", 1);
// 	b = write(fd, str, ft_strlen(str));
// 	if (b == -1)
// 		ft_exit("Failed to update the tmp heredoc file !!\n", 1);
// 	b = write(fd, "\n", 1);
// 	if (b == -1)
// 		ft_exit("Failed to update the tmp heredoc file !!\n", 1);
// 	if (close(fd) == -1)
// 		ft_exit("Failed to close tmp heredoc file !!\n", 1);
// 	printf("%s", full_path);
// 	return (full_path);
// }

// void	ft_fillheredoc(char *str)
// {
// 	// int 	a;
// 	char    *s;
// 	int		len;

// 	// a = fork();
// 	// if (!a)
// 	// {
// 		int fd = open("./dfg", O_WRONLY | O_APPEND | O_CREAT, 0644);
// 		if (fd == -1)
// 			perror("open");
// 		while (1)
// 		{
// 			s = readline("> ");
// 			if (!s || !ft_strcmp(str, s))
// 			{
// 				close(fd);
// 				break ;
// 			}
// 			len = write(fd, s, ft_strlen(s));
// 			if (len == -1)
// 				ft_exit("Here doc error", 1);
// 		}			
// 	// }
// }

// to transform a heredoc to an input file
int	main(void)
{
	int	a;

	a = fork();
	if (a == 0)
	{
	}
	else
	{
		printf("\n\n salina\n");
	}
	system ("leaks a.out");
	exit();
}
