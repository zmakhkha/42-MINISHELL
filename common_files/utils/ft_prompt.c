/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:14:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/13 16:27:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// Add a command history
void	ft_prompt(char **env)
{
	char	*str;
	// t_token	*t;
	t_env	*env_list;
	// t = NULL;
	env_list = set_env(env);
	while (1)
	{
		usleep(100);
		str = readline("minishell $ ");
		if (str == NULL)
			continue;
		ft_add_history(str);
		// t = ft_strtok(str);
		// if (!g_status && t)
		// 	ft_main_lexer(t);
		// else if (t)
		// 	printf("Lexer Error !!\n");
		// if (!g_status && t)
		// 	ft_main_ast(&t,&env_list);
		// else if (t)
		// 	printf("Lexer Error !!\n");
		// free(str);
		// t = ft_getfirst(t);
		printf("%s",ft_main_exp(str, env_list));
		puts("\n");
		// ft_free_tree(&t);
		// system("leaks minishell");
	}
}