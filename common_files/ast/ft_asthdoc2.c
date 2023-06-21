/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asthdoc2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:09:35 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/21 11:10:02 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_rmsq2(char *str, int len, char c)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_rmsq1(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = 0;
	while (str[i] && (str[i] != '\'' && str[i] != '\"'))
		i++;
	if (str[i])
		c = str[i];
	else
		return (ft_strdup(str));
	i = -1;
	while (str[++i])
	{
		if (str[i] != c)
			len++;
	}
	return (ft_rmsq2(str, len, c));
}

char	*ft_exp1(char *str)
{
	int		i;
	int		t;
	char	*res;

	res = NULL;
	t = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			t = 1;
		if (t)
			break ;
	}
	if (t == 1)
		res = ft_rmsq(str);
	return (res);
}
