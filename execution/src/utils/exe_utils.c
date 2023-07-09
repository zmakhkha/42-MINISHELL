/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 03:23:00 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/07/07 05:04:48 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_simple(t_token *list, int status)
{
	int	fd_in;
	int	fd_out;

	fd_in = dup(STDIN_FILENO);
	fd_out = dup(STDOUT_FILENO);
	if (list->type == RE_OUT)
		status = run_re_out(list);
	else if (list->type == APPEND)
		status = run_append(list);
	ft_protect(dup2(fd_in, STDIN_FILENO), "dup2", "dup2 failed");
	ft_protect(dup2(fd_out, STDOUT_FILENO), "dup2", "dup2 failed");
	return (status);
}

int	execute_word(t_token *list, t_env **env, int status)
{
	char	**splited;

	splited = ft_main_exp(list->str, *env, 0);
	if (!splited)
	{
		ft_perror(" ", CNF);
		return (127);
	}
	if (is_builtin(splited))
		status = execute_builtin(splited, list, env);
	else
		status = execute_command(splited, *env);
	ft_free_2dstr(splited);
	return (status);
}

void	free_env(t_env *env_list)
{
	t_env	*current;
	t_env	*next_node;

	current = env_list;
	while (current != NULL)
	{
		next_node = current->next;
		free(current->key);
		free(current->value);
		current->key = NULL;
		current->value = NULL;
		free(current);
		current = next_node;
	}
}
