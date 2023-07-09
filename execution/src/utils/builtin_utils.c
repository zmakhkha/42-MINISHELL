/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:20:43 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 06:18:04 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

bool	is_builtin(char **command)
{
	if (command[0] == NULL)
		return (false);
	if (!ft_strcmpl(command[0], "echo") || !ft_strncmp(command[0], "cd", 2) || \
		!ft_strcmpl(command[0], "pwd") || !ft_strncmp(command[0], "export", 6) \
		|| !ft_strncmp(command[0], "unset", 5) || !ft_strncmp(command[0], \
		"env", 3) || !ft_strncmp(command[0], "exit", 5))
	{
		return (true);
	}
	return (false);
}

int	execute_builtin(char **list, t_token *lst, t_env **env)
{
	if (list)
	{
		if (!ft_strcmp(list[0], "export"))
			return (ft_export_it(lst, env));
		else if (!ft_strcmpl(list[0], "echo"))
			return (execute_echo(list));
		else if (!ft_strcmp(list[0], "cd"))
			return (execute_cd(list, env));
		else if (!ft_strcmpl(list[0], "pwd"))
			return (execute_pwd(env));
		else if (!ft_strcmp(list[0], "unset"))
			return (execute_unset(list, env));
		else if (!ft_strcmpl(list[0], "env"))
			return (execute_env(*env));
		else if (!ft_strcmp(list[0], "exit"))
			return (execute_exit(list));
	}
	return (EXIT_FAILURE);
}

void	ft_bubble_sort(char **arr, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

char	**ft_sort_env(char **env)
{
	int		count;
	char	**sorted;
	char	**tmp;
	int		i;

	count = 0;
	tmp = env;
	while (*tmp)
	{
		count++;
		tmp++;
	}
	sorted = ft_calloc(count + 1, sizeof(char *));
	i = 0;
	tmp = env;
	while (*env)
	{
		sorted[i] = *env;
		env++;
		i++;
	}
	ft_bubble_sort(sorted, count);
	free(tmp);
	tmp = NULL;
	return (sorted);
}
