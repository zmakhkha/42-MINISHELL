/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wild_card.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:40:37 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/15 12:56:46 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_count_lmatching(t_str *src, char *cnd)
{
	int	m;
	int	i;

	i = 0;
	m = 0;
	if (src && cnd)
	{
		while (src)
		{
			while (src->str[i] && (src->str[i] == cnd[i]) \
			&& (cnd[i] != '*'))
				i++;
			if (cnd[i] == '*')
				m++;
			src = src->prev;
		}
	}
	return (m);
}

t_str	*ft_wc_left(t_str *src, char *cnd)
{
	t_str	*res;
	int		i;
	int		m;

	i = 0;
	res = NULL;
	m = ft_count_lmatching(src, cnd);
	if (m)
	{
		while (src)
		{
			i = 0;
			while (src->str[i] && (src->str[i] == cnd[i]) \
			&& (cnd[i] != '*'))
				i++;
			if (cnd[i] == '*')
				ft_str_addback(&res, ft_add_str(src->str));
			src = src->prev;
		}
	}
	return (res);
}

int	ft_count_rmatching(t_str *src, char *cnd, int len1, int len2)
{
	int	m;

	m = 0;
	if (src && cnd)
	{
		while (src)
		{
			len1 = ft_strlen(src->str);
			len2 = ft_strlen(cnd);
			while ((len1 - 1 >= 0) && src->str[len1 - 1] \
			&& (src->str[len1 - 1] == cnd[len2 - 1]) \
			&& (cnd[len2 - 1] != '*'))
			{
				len1--;
				len2--;
			}
			if (cnd[len2 - 1] == '*')
				m++;
			src = src->prev;
		}
	}
	return (m);
}

t_str	*ft_wc_right(t_str *src, char *cnd)
{	
	int		len1;
	int		len2;
	int		j;
	t_str	*res;
	int		m;

	m = 0;
	j = 0;
	len1 = 0;
	len2 = 0;
	res = NULL;
	m = ft_count_rmatching(src, cnd, len1, len2);
	if (m)
	{
		while (src)
		{
			len1 = ft_strlen(src->str);
			len2 = ft_strlen(cnd);
			while ((len1 - 1 >= 0) && src->str[len1 - 1] \
			&& (src->str[len1 - 1] == cnd[len2 - 1]) \
			&& (cnd[len2 - 1] != '*'))
			{
				len1--;
				len2--;
			}
			if (cnd[len2 - 1] == '*')
				ft_str_addback(&res, ft_add_str(src->str));
			src = src->prev;
		}
	}
	return (res);
}

int	ft_count(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i++] == '*')
				c++;
		}
	}
	if (c == 1 && *str == '*')
		return (RIGHT);
	else if (c == 1 && str[i - 1] == '*')
		return (LEFT);
	else if (c >= 1)
		return (MULT);
	return (0);
}

t_str	*ft_matching(t_str *src, char *str)
{
	int		a;
	t_str	*res;

	a = -1;
	res = NULL;
	if (str && src)
	{
		a = ft_count(str);
		if (a == LEFT)
			res = ft_wc_left(src, str);
		else if (a == RIGHT)
			res = ft_wc_right(src, str);
	}
	return (res);
}

// # define LEFT 0
// # define RIGHT 1
// # define MULT 2

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
	directory = opendir(path);
	path = "/Users/zmakhkha/Desktop/minishell-dev-version";
	if (directory == NULL)
		perror("Failed to open the directory");
	i = 0;
	while ((dir = readdir(directory)) != NULL)
		i++;
	closedir(directory);
	directory = opendir(path);
	i = 0;
	puts("\n");
	res = NULL;
	while ((dir = readdir(directory)) != NULL)
	{
		tmp = (char *) dir->d_name;
		ft_str_addback(&res, ft_add_str(ft_strdup(tmp)));
	}
	closedir(directory);
	return (res);
}

void	ft_main_wc(char	*str, t_env	*env_list)
{
	t_str	*r;
	t_str	*b;

	r = ft_dirfiles(env_list);
	b = ft_matching(r, str);
	if (b)
		puts("hooya");
	while (b)
	{
		puts(b->str);
		b = b->prev;
	}
}
