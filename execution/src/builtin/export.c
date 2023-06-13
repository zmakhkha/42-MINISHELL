/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:01:54 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/13 09:01:50 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_export(char **list, t_env **env_list)
{
	char	**split;
	char	*key;
	char	*value;

	if (!list[1])
	{
		declare_env(env_list);
		return (EXIT_SUCCESS);
	}
	if (list[1])
	{
		split = ft_split(list[1], '=');
		if (!split)
			return (EXIT_FAILURE);
		key = split[0];
		value = split[1];
		change_env(key, value, env_list);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
