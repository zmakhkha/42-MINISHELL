/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:41:47 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 16:44:21 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_isquote(char *str)
{
	if (str)
	{
		while (str)
		{
			if ((*str) == '\'' || (*str) == '\"')
				return (1);
		}
	}
	return (0);
}

char	**ft_format(char *str)
{
	char	**spl;

	spl = ft_split(str, ' ');
	if (str)
		free(str);
	str = NULL;
	return (spl);
}

void	ft_strrep(char *str, char a, char b)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == a)
			str[i] = b;
	}
}
