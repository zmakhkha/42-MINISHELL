/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:14:09 by zmakhkha          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/24 10:35:55 by ayel-fil         ###   ########.fr       */
=======
/*   Updated: 2023/06/23 16:52:22 by zmakhkha         ###   ########.fr       */
>>>>>>> parent of ab0bb26... Merge pull request #21 from zmakhkha/exe
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_check(char *str)
{
	if (ft_strchr(str, '`') || ft_strchr(str, '^') || ft_strchr(str, '@') \
	|| ft_strchr(str, '!') || ft_strchr(str, '#') || ft_strchr(str, '-'))
		g_status = 1;
	return (1);
}

void	ft_free_env(t_env **env)
{
	if (env && *env)
	{
		ft_free_env(&(*env)->next);
		if ((*env)->key)
		{
			free ((*env)->key);
			(*env)->key = NULL;
		}
		if ((*env)->value != NULL)
		{
			free ((*env)->value);
			(*env)->value = NULL;
		}
		free(*env);
		(*env) = NULL;
		env = NULL;
	}
}

void	ft_run_it(char *str, t_env	*env_list)
{
	t_token	*t;
	t = NULL;

	ft_add_history(str);
		t = ft_strtok(str);

		if (!g_status && t)
		{
		ft_main_lexer(t);
		}
		else if (t)
			printf("Parsing Error !!\n");
		if (!g_status && t)
			ft_main_ast(&t,&env_list);
		else if (t)
			printf("Lexing Error !!\n");
		t = ft_getfirst(t);
		ft_free_tree(&t);
}

void	ft_free_2dstr(char **str)
{
	int	i;

	i = 0;
	while(str && str[i])
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

// Add a command history
void	ft_prompt(char **env)
{
	char	*str;
	char	*str1;
	t_env	*env_list;
	env_list = set_env(env);
<<<<<<< HEAD
	if (env_list == NULL)
	{
		add_env_node("PWD", getcwd(NULL, 0), &env_list);
		change_env("PATH",VALUE_PATH,&env_list);
		change_env("SHLVL", "1", &env_list);
		change_env("_", "/usr/bin/env", &env_list);
	}
=======
>>>>>>> parent of ab0bb26... Merge pull request #21 from zmakhkha/exe
	// ft_free_envstr(env);
	while (1)
	{
		// usleep(100);
		str = readline("minishell $ ");
		if (str == NULL)
			break;
		ft_run_it(str, env_list);
		free(str);
		// break;
	}
	ft_free_env(&env_list);
	// system("leaks minishell");
}