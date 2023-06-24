/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_utils.c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:12:42 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/24 08:43:37 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int run_re_in(t_token *list, t_env *env)
{
	int fd;
	int in_fd;
	int status;

	status = EXIT_SUCCESS;
	fd = ft_protect(open(list->left->str, O_RDONLY, 0644), "open", "open failed");
	in_fd = dup(STDIN_FILENO);
	ft_protect(dup2(fd, STDIN_FILENO), "dup2", "dup2 failed");
	ft_protect(close(fd), "close", "close failed");
	status = ft_execution(list->right, env);
	ft_protect(dup2(in_fd, STDIN_FILENO), "dup2", "dup2 failed");
	return status;
}

int run_re_out(t_token *list, t_env *env)
{
	int fd;
	int out_fd;
	int status;

	status = EXIT_SUCCESS;
	fd = ft_protect(open(list->left->str, O_WRONLY | O_TRUNC | O_CREAT, 0644), "open", "open failed");
	out_fd = dup(STDOUT_FILENO);
	ft_protect(dup2(fd, STDOUT_FILENO), "dup2", "dup2 failed");
	ft_protect(close(fd), "close", "close failed");
	status = ft_execution(list->right, env);
	ft_protect(dup2(out_fd, STDOUT_FILENO), "dup2", "dup2 failed");
	return status;
}

int run_append(t_token *list, t_env *env)
{
	int fd;
	int out_fd;
	int status;

	status = EXIT_SUCCESS;
	fd = ft_protect(open(list->left->str, O_WRONLY | O_CREAT | O_APPEND, 0644), "open", "open failed");
	out_fd = dup(STDOUT_FILENO);
	ft_protect(dup2(fd, STDOUT_FILENO), "dup2", "dup2 failed");
	ft_protect(close(fd), "close", "close failed");
	status = ft_execution(list->right, env);
	ft_protect(dup2(out_fd, STDOUT_FILENO), "dup2", "dup2 failed");
	return status;
}
