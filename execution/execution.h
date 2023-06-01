/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 01:56:35 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/05/29 02:17:07 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../header.h"


enum				e_fd
{
	ER = STDERR_FILENO,
	IN = STDIN_FILENO,
	OUT = STDOUT_FILENO
};

t_env				*set_env(char **env);
char				*find_env_node(char *key, t_env *env_list);
#endif