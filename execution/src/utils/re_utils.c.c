/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_utils.c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:12:42 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/26 02:58:00 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	run_re_in(t_token *list, t_env *env)
{
	int	fd;
	// int	in_fd;
	// fd = -1;
	printf("am in\n");
	int	status;
(void)env;
	if (!list)
		return (0);
	status = EXIT_SUCCESS;
	puts(list->str);
	fd = open(ft_strtrim(list->str, " "), O_RDONLY, 0644);
	printf("%d\n", fd);
	
	if (fd < 0)
		return (perror("minishell: "), -1);
	ft_protect(dup2(fd, STDIN_FILENO), "dup2", "dup2 failed");
	ft_protect(close(fd), "close", "close failed");
	// status = ft_execution(list->right, env);
	// ft_protect(dup2(in_fd, STDIN_FILENO), "dup2", "dup2 failed");
	return (status);
}
int	run_re_out(t_token *list, t_env *env)
{
	int	fd;
	int	out_fd;
	int	status;
	(void)env;
	if (!list)
		return (0);
	status = EXIT_SUCCESS;
	fd = open(ft_strtrim(list->str, " "),O_WRONLY | O_TRUNC | O_CREAT,0644);
	if (fd < 0)
		return (perror("minishell: "), -1);
	out_fd = dup(STDOUT_FILENO);
	ft_protect(dup2(fd, STDOUT_FILENO), "dup2", "dup2 failed");
	ft_protect(close(fd), "close", "close failed");
	// status = ft_execution(list->right, env);
	// ft_protect(dup2(out_fd, STDOUT_FILENO), "dup2", "dup2 failed");
	return (status);
}

int	run_append(t_token *list, t_env *env)
{
	int	fd;
	int	out_fd;
	int	status;
(void)env;
	if (!list)
		return (0);
	status = EXIT_SUCCESS;
	fd = open(list->left->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (perror("minishell: "), -1);
	out_fd = dup(STDOUT_FILENO);
	ft_protect(dup2(fd, STDOUT_FILENO), "dup2", "dup2 failed");
	ft_protect(close(fd), "close", "close failed");
	// status = ft_execution(list->right, env);
	// ft_protect(dup2(out_fd, STDOUT_FILENO), "dup2", "dup2 failed");
	return (status);
}
