/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:13:57 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/13 16:39:33 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

# include "libft/libft.h"

# define H_PATH "/tmp/.minishell_history"

# define COMMAND	0
# define AND		1
# define OR			2
# define RE_IN		3
# define RE_OUT		4

typedef struct s_token
{
	char	*str;
	int		len;
	int		type;
}	t_token;

// common_files/ft_prompt.c
void	ft_print(char *a);
void	ft_prompt(void);
int		ft_add_history(char *tmp);

// common_files/ft_exit_utils.c
void	ft_exit(char *c, int s);

// common_files/token_utils.c
t_token	*tokenize_it(char *str);
void	free_token(t_token *t);

#endif