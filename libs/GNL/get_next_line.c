/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:36:24 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/21 17:50:04 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static size_t	ft_len(const char *s, int choice)
{
	int	i;

	i = 0;
	if (choice == 1)
	{
		while (s[i])
			i += 1;
		return (i);
	}
	else
	{
		while (s[i] && s[i] != '\n')
			i += 1;
		return (i);
	}
	return (0);
}

static char	*ft_read(int fd, char *line, char *chunk)
{
	int	ret;
	int	line_i;

	ret = 1;
	while (!ft_strchr(line, '\n') && ret)
	{
		if (*chunk == '\0')
		{
			ret = read(fd, chunk, BUFFER_SIZE);
			if ((ret == 0 && !*line) || ret == -1)
				return (free(line), NULL);
			chunk[ret] = '\0';
		}
		line = ft_strjoin(line, chunk);
		if (!ft_strchr(line, '\n'))
			*chunk = '\0';
	}
	if (ft_strchr(line, '\n'))
	{
		line_i = ft_len(line, 2) + 1;
		ft_memcpy(chunk, &line[line_i], ft_len(line, 1) - line_i + 1);
		line = ft_substr_gnl(line, 0, line_i);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*temp;
	char		*line;
	static char	chunk[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_strdup("");
	if (!line)
		return (line);
	temp = ft_read(fd, line, chunk);
	return (temp);
}
