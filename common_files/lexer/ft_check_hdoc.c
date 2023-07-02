/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hdoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:35:28 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/20 19:35:28 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

//Check for the here doc delimiter
int	ft_check_hdoc(t_token *lst)
{
	int	i;

	i = SUCC;
	if (lst && lst->prev)
	{
		if (ft_getlast(lst)->type == HDOC)
			i = ERR;
		while (lst)
		{
			if (lst->type == HDOC && (\
				!ft_valid_hd_delim(lst->prev) || !lst->prev))
			{
				printf("heredoc delimiter error !!\n");
				i = ERR;
				g_glob.g_status = ERR;
				break ;
			}
			lst = lst->prev;
		}
	}
	return (i);
}

char	*ft_heredoc(char *del)
{
	char	*hdoc;
	char	*star;

	star = NULL;
	hdoc = NULL;
	g_glob.g_ctrl_c = false;
	while (1)
	{
		star = readline("> ");
		if (star == NULL || !ft_strcmp(del, star) || g_glob.g_ctrl_c)
			break ;
		else
		{
			if (hdoc)
				hdoc = ft_join_free(hdoc, ft_strdup("\n"));
			hdoc = ft_join_free(hdoc, star);
		}
	}
	return (hdoc);
}

void	ft_write_to_file(int fd, ssize_t b, char *str, char *full_path)
{
	fd = open(full_path, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		ft_exit("Failed to create the tmp heredoc file !!\n", 1);
	if (str)
	{
		b = write(fd, str, ft_strlen(str));
		if (b == -1)
			ft_exit("Failed to update the tmp heredoc file !!\n", 1);
		b = write(fd, "\n", 1);
		if (b == -1)
			ft_exit("Failed to update the tmp heredoc file !!\n", 1);
	}
	if (close(fd) == -1)
		ft_exit("Failed to close tmp heredoc file !!\n", 1);
}

char	*ft_hdoc_tofd(char *str, int type, t_env *env_list)
{
	int		fd;
	char	*path;
	char	*full_path;
	ssize_t	b;

	b = 0;
	fd = 0;
	path = ft_strdup("HDOC");
	full_path = ft_join_free(ft_strdup(H_DOCP), path);
	if (type == 1)
		str = ft_expand(str, env_list);
	while (access(full_path, F_OK) == 0)
		full_path = ft_join_free(full_path, ft_strdup("_1"));
	ft_write_to_file(fd, b, str, full_path);
	free(str);
	return (full_path);
}
