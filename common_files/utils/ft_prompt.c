/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:14:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/21 14:37:10 by zmakhkha         ###   ########.fr       */
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
			printf("Lexer Error !!\n");
		if (!g_status && t)
			ft_main_ast(&t,&env_list);
		else if (t)
			printf("Parser Error dsds!!\n");
		t = ft_getfirst(t);
		free(str);
		ft_free_tree(&t);
		// system("leaks minishell");
	
}

// Add a command history
void	ft_prompt(char **env)
{
	char	*str;
	t_env	*env_list;
	env_list = set_env(env);
	while (1)
	{
		// usleep(100);
		str = readline("minishell $ ");
		if (str == NULL )
			break;
		ft_run_it(str, env_list);
	}
}