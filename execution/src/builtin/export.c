/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:01:54 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/21 18:07:11 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	handle_export_argument(char *arg, t_env **env_list)
{
	char	**splited;
	char	*key;
	char	*value;

	splited = ft_split(arg, '=');
	if (splited && splited[0] && splited[1])
	{
		key = ft_strdup(splited[0]);
		value = ft_strdup(splited[1]);
		change_env(key, value, env_list);
		free(key);
		free(value);
		ft_free_2darray((void **)splited);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf("Invalid format: %s\n", arg);
		if (splited)
			ft_free_2darray((void **)splited);
		return (EXIT_FAILURE);
	}
}

int	execute_export(char **args, t_env **env_list)
{
	int	i;

	i = 1;
	if (args[0] && !args[1])
	{
		declare_env(env_list);
		return (EXIT_SUCCESS);
	}
	while (args[i] != NULL)
	{
		if (handle_export_argument(args[i], env_list))
			return (EXIT_FAILURE);
		key = split[0];
		value = split[1];
		change_env(key, value, env_list);
		ft_free_2dstr(split);
		return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_SUCCESS);
}
