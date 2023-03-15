/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:13:57 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/15 18:21:25 by zmakhkha         ###   ########.fr       */
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

enum
{
	WORD,
	PIPE,
	SUBSHELL,
	COMMAND,
	AND,
	OR,
	RE_IN,
	RE_OUT,
	HDOC,
	APPEND,
	W_CARD,
	DQ_COMM,
	SQ_COMM
};

typedef struct s_token
{
	char			*str;
	int				len;
	int				type;
	struct s_token	*prev;
}	t_token;

// common_files/ft_prompt.c
void	ft_print(char *a);
void	ft_prompt(void);
int		ft_add_history(char *tmp);

// common_files/token_utils.c
void	ft_pr(int a);
t_token	*ft_add_token(char *str, int type);
void	ft_token_addback(t_token **lst, t_token *new);
void	ft_free_token(t_token **t);

// common_files/ft_string_utils.c
void	white_comm(char *str, t_token **lst, int *a, int *b);
void	d_quotes(char *str, t_token **lst, int *a, int *b);
void	s_quotes(char *str, t_token **lst, int *a, int *b);
void	ft_operators(char *str, t_token **lst, int *a, int *b);
void	ft_prt(char *str, t_token **lst, int *a, int *b);

// common_files/ft_string_utils2.c
int	ft_is_operator2(char c);
void	ft_operators2(char *str, t_token **lst, int *a, int *b);
t_token	*ft_strtok(char *str);

// common_files/ft_utils.c
void	ft_exit(char *c, int s);
int		ft_is_valid_comm(char c);
int		ft_is_whitespace(char c);
int		ft_is_operator(char c);
int		ft_is_quote(char c);

#endif