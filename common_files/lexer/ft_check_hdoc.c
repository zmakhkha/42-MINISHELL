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

//Valid here doc delimiter
int	ft_valid_hd_delim(t_token *lst)
{
	if (lst)
		return (lst->type == WORD || \
		lst->type == FILE_);
	return (0);
}

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
	hdoc = (char *)ft_calloc(1, 1);
	while (1)
	{
		star = readline("> ");
		if (star == NULL || !ft_strcmp(del, star))
			break ;
		else
			hdoc = ft_join_free(ft_join_free(hdoc, star), "\n");
		free (star);
	}
	return (hdoc);
}

char *ft_twotoone(char **table)
{
	int		i;
	char	*res;
	char	*tmp;

	puts("lalalalalalalalahahahahahahahahahahahahahahahahhahaa");
	res = NULL;
	tmp = NULL;
	i = -1;
	while (table && table[++i])
	{
		
		tmp = ft_join_free(res, table[i]);
		res = ft_join_free(tmp, " ");
		free(tmp);
	}
	ft_free_2dstr(table);
	return (res);
}

char	*ft_hdoc_tofd(char *str, int type, t_env *env_list)
{
	int		fd;
	char	*path;
	char	*full_path;
	char	**tm;
	ssize_t	b;

	b = 0;
	path = ft_join_free("HDOC", " ");
	full_path = ft_join_free(H_DOCP, path);
	if (type == 1)
	{
		tm = ft_main_exp(str, env_list);
		str = ft_twotoone(tm); 
	}
	while (access(full_path, F_OK) == 0)
		full_path = ft_join_free(full_path, "_1");
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
	free (str);
	return (full_path);
}

// void	main_hdoc_to_file(t_token **list, char *name)
// {
// 	int	a;
// 	(void)list;
// 	a = fork();
// 	if (a == 0)
// 	{
// 		ft_hdoc_tofd(ft_heredoc(NULL, name));
// 	}
// 	else
// 		waitpid(a, NULL, 0);
// }
