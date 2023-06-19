/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:18:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/18 18:39:36 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


// returns anarrays of elements names

t_str	*ft_dirfiles(t_env *env_list)
{
	char			*path;
	char			*tmp;
	struct dirent	*dir;
	t_str			*res;
	int				i;
	DIR				*directory;

	(void)env_list;
	path = "/Users/zmakhkha/Desktop/MINISHELL"; // to replace with the pwd value
	directory = opendir(path);
	if (directory == NULL)
	{
		perror("Failed to open the directory");
		return (NULL);
	}
	i = 0;
	while ((dir = readdir(directory)) != NULL)
		i++;
	closedir(directory);
	directory = opendir(path);
	i = 0;
	res = NULL;
	while ((dir = readdir(directory)) != NULL)
	{
		tmp = (char *) dir->d_name;
		if (tmp[0] != '.')
			ft_str_addback(&res, ft_add_str(ft_strdup(tmp)));
	}
	closedir(directory);
	return (res);
}