/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:14:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/19 11:38:10 by ayel-fil         ###   ########.fr       */
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

// Add a command history
void	ft_prompt(char **env)
{
	char	*str;
	t_token	*t;
	t_env	*env_list;
	t = NULL;
	env_list = set_env(env);
	while (1)
	{
		// usleep(100);
		str = readline("minishell $ ");
		if (str == NULL )
			break;
		ft_add_history(str);
		t = ft_strtok(str);
		if (!g_status && t)
			ft_main_lexer(t);
		else if (t)
			printf("Lexer Error !!\n");
		if (!g_status && t)
			ft_main_ast(&t,&env_list);
		else if (t)
			printf("Lexer Error !!\n");
		t = ft_getfirst(t);
		// printf("%s",ft_main_exp(str, env_list));
		free(str);
		ft_free_tree(&t);
		// system("leaks minishell");
	}
}