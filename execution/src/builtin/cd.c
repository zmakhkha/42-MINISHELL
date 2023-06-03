/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:42:09 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/03 04:20:23 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

void	execute_cd(t_token *list)
{
	int res = 0;
	if (!list->left)
	{
		printf("Error: path not specified\n");
		return ;
	}

	if (list->left->left)
	{
		printf("Error: too many arguments\n");
		return ;
	}

	// Check if the path is relative or absolute
	char *path = list->left->str;
	res = chdir(path);
	if (res == -1)
		perror("cd");
	if (access(getenv("PWD"), F_OK) && !ft_strcmp(path, "."))
	{
		ft_putendl_fd("cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory",
						ERR);
		return ;
	}
	return ;
}