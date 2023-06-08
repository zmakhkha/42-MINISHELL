/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:16:38 by ayel-fil          #+#    #+#             */
/*   Updated: 2022/10/23 10:48:52 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add.h"

static void	free_arrays(char **array, int index)
{
	while (index >= 0)
		free(array[index--]);
	free(array);
}

static size_t	count_arrays(char const *string, char seperator)
{
	size_t	i;
	size_t	counts;

	counts = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] != seperator && (string[i + 1] == seperator || !string[i
					+ 1]))
			counts++;
		i++;
	}
	return (counts);
}

static void	make_arrays(char **split, char c, char const *s)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	while (i < count_arrays(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		split[i] = ft_substr(s, start, (end - start));
		if (split[i] == NULL)
		{
			free_arrays(split, i - 1);
			return ;
		}
		start = end;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = ft_calloc((count_arrays(s, c) + 1), (sizeof(char *)));
	if (!split)
		return (NULL);
	make_arrays(split, c, s);
	return (split);
}
