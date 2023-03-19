/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:13:57 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/18 21:18:28 by zmakhkha         ###   ########.fr       */
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
# define SUCC 0
# define ERR 1

// -------> Tokens enumeration <------- //

enum
{
	WORD,
	PIPE,
	// SPACE,
	SUBSHELL,
	AND,
	OR,
	RE_IN,
	RE_OUT,
	HDOC,
	APPEND,
	W_CARD,
	DQ_COMM,
	SQ_COMM,
	DOLLAR,
	QST
};

// -------------------------------------- //
// -----------> Token struct <---------- //
// ------------------------------------ //

typedef struct s_command
{
	char			**str[0];
	struct s_token	*prev;
}	t_command;

// -------------------------------------- //
// -----------> Token struct <---------- //
// ------------------------------------ //

typedef struct s_token
{
	char			*str;
	int				index;
	int				type;
	struct s_token	*prev;
}	t_token;

// -------------------------------------- //
// --------------> Utils <-------------- //
// ------------------------------------ //

// common_files/utils/ft_history_utils.c
int		ft_add_history(char *str);
void	ft_print(char *a);

// common_files/utils/ft_prompt.c
void	ft_prompt(void);

// common_files/utils/ft_token_utils.c
t_token	*ft_add_token(char *str, int type);
t_token	*ft_getlast(t_token *lst);
void	ft_token_addback(t_token **lst, t_token *new);
void	ft_free_token(t_token **t);

// -------------------------------------- //
// -------> The tokenizer stage <------- //
// ------------------------------------ //

// common_files/tokenizer/ft_string_utils.c
void	ft_word(char *str, t_token **lst, int *a, int *b);
void	d_quotes(char *str, t_token **lst, int *a, int *b);
void	s_quotes(char *str, t_token **lst, int *a, int *b);
void	ft__operators(char *str, t_token **lst, int *a, int *b);
void	ft_operators(char *str, t_token **lst, int *a, int *b);

// common_files/tokenizer/ft_string_utils2.c
void	ft_space(char *str, t_token **lst, int *a, int *b);
void	ft_operators2(char *str, t_token **lst, int *a, int *b);
void	ft_operators3(char *str, t_token **lst, int *a, int *b);
int		if_validp(char *str);
void	ft_prt(char *str, t_token **lst, int *a, int *b);

// common_files/tokenizer/ft_string_utils3.c
int		ft_voperator(char*str, char op);
int		ft_validouble(char *str, char op);

// common_files/tokenizer/ft_string_utils4.c
int		ft_forbidden(char c);
int		ft_is_operators4(char c);
void	ft_operators4(char *str, t_token **lst, int *a, int *b);

// common_files/tokenizer/ft_token_utils.c
void	ft__strtok(char *str, t_token **lst, int *a, int *b);
t_token	*ft_strtok(char *str);

// common_files/tokenizer/ft_valid_utils.c
int		ft_is_operator(char c);
int		ft_is_moperator(char c);
int		ft_is_operator4(char c);
int		ft_is_operator2(char c);
int		ft_is_quote(char c);

//common_files/tokenizer/ft_valid_utils2.c
void	ft_exit(char *c, int s);
int		ft_valid_word(char c);
int		ft_is_valid_comm2(char c);
int		ft_is_whitespace(char c);
int		ft_is_operator3(char c);

// -------------------------------------- //
// ---------> The Lexer stage <--------- //
// ------------------------------------ //

// common_files/lexer/ft_check_errors.c
int		ft_check_operators(t_token *lst);
int		if_valid_re_floower(t_token *node);
int		ft_check_redirections(t_token *lst);

// common_files/lexer/ft_main_lexer.c
void	ft_position_it(t_token **lst);
void	ft_main_lexer(t_token *lst);

// common_files/utils/ft_strings.c
int		ft_strcmp(char *s1, char *s2);

#endif