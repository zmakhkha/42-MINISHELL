/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_utils.c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:12:42 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 01:40:59 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	run_re_in(t_token *list)
{
	int		fd;
	int		status;
	char	*filename;

	if (!list)
		return (0);
	status = EXIT_SUCCESS;
	filename = ft_strtrim(list->str, " ");
	if (!filename)
		return (EXIT_FAILURE);
	fd = open(filename, O_RDONLY, 0644);
	if (fd == -1)
	{
		perror(filename);
		free(filename);
		filename = NULL;
		return (EXIT_FAILURE);
	}
	ft_protect(dup2(fd, STDIN_FILENO), "dup2", "dup2 failed");
	ft_protect(close(fd), "close", "close failed");
	free(filename);
	filename = NULL;
	return (status);
}

int	run_re_out(t_token *list)
{
	int		fd;
	int		status;
	char	*filename;

	if (!list)
		return (0);
	status = EXIT_SUCCESS;
	filename = ft_strtrim(list->str, " ");
	if (!filename)
		return (EXIT_FAILURE);
	fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		perror(filename);
		free(filename);
		filename = NULL;
		return (EXIT_FAILURE);
	}
	ft_protect(dup2(fd, STDOUT_FILENO), "dup2", "dup2 failed");
	ft_protect(close(fd), "close", "close failed");
	free(filename);
	filename = NULL;
	return (status);
}

int	run_append(t_token *list)
{
	int		fd;
	int		status;
	char	*filename;

	if (!list)
		return (0);
	status = EXIT_SUCCESS;
	filename = ft_strtrim(list->str, " ");
	if (!filename)
		return (EXIT_FAILURE);
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(filename);
		free(filename);
		filename = NULL;
		return (EXIT_FAILURE);
	}
	ft_protect(dup2(fd, STDOUT_FILENO), "dup2", "dup2 failed");
	ft_protect(close(fd), "close", "close failed");
	free(filename);
	filename = NULL;
	return (status);
}
