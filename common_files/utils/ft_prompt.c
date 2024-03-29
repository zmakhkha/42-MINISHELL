/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:14:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/09 16:35:24 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_free_env(t_env **env)
{
	if (env && *env)
	{
		ft_free_env(&(*env)->next);
		if ((*env)->key)
		{
			free((*env)->key);
			(*env)->key = NULL;
		}
		if ((*env)->value != NULL)
		{
			free((*env)->value);
			(*env)->value = NULL;
		}
		free(*env);
		(*env) = NULL;
		env = NULL;
	}
}

void	ft_run_it(char *str, t_env **env_list)
{
	t_token	*t;

	t = NULL;
	t = ft_strtok(str);
	if (!g_glob.g_status && t)
	{
		ft_main_lexer(t);
	}
	else if (t)
	{
		g_glob.g_status_exit = 258;
		printf("Parsing Error !!\n");
	}
	if (!g_glob.g_status && t)
		ft_main_ast(&t, env_list);
	else if (t)
	{
		g_glob.g_status_exit = 258;
		printf("Lexing Error !!\n");
	}
	t = ft_getfirst(t);
	ft_free_tree(&t);
}

void	ft_free_2dstr(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i])
			free(str[i]);
		str[i] = NULL;
		i++;
	}
	if (str)
		free(str);
	str = NULL;
}

void	ft_set(t_env **env_list)
{
	add_env_node("PATH", VALUE_PATH, env_list);
	change_env("PWD", getcwd(NULL, 0), env_list);
	change_env("SHLVL", "1", env_list);
	change_env("_", "/usr/bin/env", env_list);
}

// Add a command history
void	ft_prompt(char **env)
{
	char	*str;
	t_env	*env_list;

	env_list = set_env(env);
	if (env_list == NULL)
		ft_set(&env_list);
	while (1)
	{
		str = readline("minishell $ ");
		if (str == NULL)
		{
			write(1, "exit\n", 5);
			break ;
		}
		ft_add_history(str);
		ft_run_it(str, &env_list);
		free(str);
	}
	ft_free_env(&env_list);
}
