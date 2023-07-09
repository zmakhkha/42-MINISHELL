/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:01:54 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/01 15:07:09 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	check_if_valid(char *arg)
{
	if (!ft_isalpha(arg[0]))
	{
		ft_perror(arg, "not a valid identifier");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_arguments(char *arg, char **key, char **value)
{
	int	j;

	j = 0;
	while (arg[j] && arg[j] != '=')
	{
		j++;
	}
	*key = ft_calloc(j + 1, sizeof(char));
	*value = NULL;
	ft_strlcpy(*key, arg, j + 1);
	if (arg[j] == '=')
	{
		*value = ft_calloc(ft_strlen(arg) - j, sizeof(char));
		ft_strlcpy(*value, (arg + j + 1), (ft_strlen(arg) - j));
	}
	return (EXIT_SUCCESS);
}

int	execute_export(char **args, t_env **env_list)
{
	int		i;
	char	*key;
	char	*value;
	int		ret;

	i = 1;
	ret = 0;
	if (args == NULL)
	{
		return (0);
	}
	if (args[0] && !args[1])
	{
		declare_env(env_list);
	}
	while (args[i])
	{
		ret = check_if_valid(args[i]);
		parse_arguments(args[i], &key, &value);
		if (!ret)
			change_env(key, value, env_list);
		i++;
	}
	return (0);
}
