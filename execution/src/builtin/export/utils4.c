/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:33:34 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/02 23:53:25 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header.h"

int	ft_envlen(t_env *env)
{
	int i;

	i = 0;
	while (env)
	{
		i += 1;
		env = env->next;
	}
	return (i);
}

char	**ft_env_to_char(t_env *env)
{
	int     len;
	char    **tmp;
	int		i;

	i = 0;
	len = ft_envlen(env);
	tmp = ft_calloc(len + 1, sizeof(char *));
	while(env)
	{
		tmp[i] = env->key;
		i++;
		env = env->next;
	}
	return (tmp);
}

void	ft_sort_char(char **table)
{
	char	*tmp;
	int		i;

	i = 0;
	
	while (table && table[i] && table[i + 1])
	{
		if (ft_strcmp(table[i], table[i + 1]) > 0)
		{
			tmp = table[i];
			table[i] = table[i + 1];
			table [i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	i = -1;
	while (table[++i])
		puts(table[i]);
}