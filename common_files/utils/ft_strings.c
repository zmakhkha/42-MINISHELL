/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:11:44 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/05 12:22:07 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

size_t	ft_strlenp(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmplen(char *s1, char *s2)
{
	int	i;
	int	l1;
	int	l2;

	i = -1;
	if (s1 && s2)
	{
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		if (l1 != l2)
			return (i);
		while (l1 && s1[l1] == s2[l1])
			l1--;
		return (s1[l1] - s2[l1]);
	}
	return (-1);
}

void	ft_freee(char *s1, char *s2)
{
	if (s1)
		free(s1);
	s1 = NULL;
	if (s2)
		free(s2);
	s2 = NULL;
}

// free the two chars and returns the result allocated
char	*ft_join_free(char *s1, char *s2)
{
	size_t		l1;
	size_t		l2;
	int			i;
	char		*res;

	res = s1;
	if (s2)
	{
		l1 = ft_strlenp(s1);
		l2 = ft_strlenp(s2);
		res = malloc(l1 + l2 + 1);
		if (!res)
			ft_exit("Allocation error !!", 1);
		i = -1;
		while (++i < (int)l1)
			res[i] = s1[i];
		i = -1;
		while (++i < (int)l2)
			res[l1 + i] = s2[i];
		res[l1 + i] = 0;
		ft_freee(s1, s2);
	}
	if (res && !ft_strlen(res))
		return (free(res), NULL);
	return (res);
}
