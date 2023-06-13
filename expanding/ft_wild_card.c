/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wild_card.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:40:37 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/13 19:26:39 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	**ft_dirfiles(t_env *env_list)
{
	char *path;
	struct dirent *dir;
	char	**res;
	(void)env_list;
	int i = 0;

	path = "/Users/zmakhkha/Desktop";
	DIR *directory = opendir(path);
	if (directory == NULL)
		perror("Failed to open the directory");
	while ((dir = readdir(directory)) != NULL)
		i++;
	res = (char **)malloc(sizeof(char *) * i);
	closedir(directory);
	res = (char **)malloc(sizeof(char *) * i);
	if (!res)
		ft_exit("Allocation failed !!", 1);
	DIR *directory1 = opendir(path);
	if (directory1 == NULL)
		perror("Failed to open the directory1");
	i = 0;
	while ((dir = readdir(directory1)) != NULL)
	{
		res[i] = ft_strdup(dir->d_name);
		i++;
	}
	closedir(directory1);
	printf("%d", i);
	return (NULL);
}
void	ft_main_wc(char	*str, t_env	*env_list)
{
	(void)str;
	char	**a = ft_dirfiles(env_list);
	int		i = 0;
	while(a && a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
}