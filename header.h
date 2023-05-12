/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:13:57 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/12 15:04:47 by zmakhkha         ###   ########.fr       */
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
# define H_DOCP "/tmp/"
# define SUCC 0
# define ERR 1

// -------> Tokens enumeration <------- //

enum
{
	WORD,
	FILE_,
	PIPE,
	SPACE,
	SUBSHELL,
	AND,
	OR,
	RE_IN,
	RE_OUT,
	HDOC,
	APPEND,
	W_CARD,
	QUOTE,
	SQ_COMM,
	DOLLAR,
	QST
};

// -------------------------------------- //
// ----------> Command struct <--------- //
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
	int				fd;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

// -------------------------------------- //
// -----------> Token struct <---------- //
// ------------------------------------ //

typedef struct s_tree
{
	char			**str;
	t_command		comm;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

// -------------------------------------- //
// -------> The tokenizer stage <------- //
// ------------------------------------ //

// common_files/tokenizer/ft_string_utils.c
void	ft_word(char *str, t_token **lst, int *a, int *b);
int		d_quotes(char *str, t_token **lst, int *a, int *b);
int		s_quotes(char *str, t_token **lst, int *a, int *b);
int		ft_operators(char *str, t_token **lst, int *a, int *b);
void	ft__operators(char *str, t_token **lst, int *a, int *b);

// common_files/tokenizer/ft_string_utils2.c
void	ft_space(char *str, t_token **lst, int *a, int *b);
int		ft_operators2(char *str, t_token **lst, int *a, int *b);
int		ft_operators3(char *str, t_token **lst, int *a, int *b);
int		ft_prt(char *str, t_token **lst, int *a, int *b);
int		if_validp(char *str);

// common_files/tokenizer/ft_string_utils3.c
int		ft_voperator(char*str, char op);
int		ft_validouble(char *str, char op);

// common_files/tokenizer/ft_string_utils4.c
int		ft_forbidden(char c);
int		ft_is_operators4(char c);
void	ft_operators4(char *str, t_token **lst, int *a, int *b);

// common_files/tokenizer/ft_token_utils.c
int		ft__strtok(char *str, t_token **lst, int *a, int *b);
t_token	*ft_strtok(char *str);
t_token *ft_main_token(t_token *lst);

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
// --------------> Utils <-------------- //
// ------------------------------------ //

// common_files/utils/ft_history_utils.c
int		ft_add_history(char *str);
void	ft_print(char *a);

// common_files/utils/ft_prompt.c
void	ft_prompt(void);

// common_files/utils/ft_strings.c
int		ft_strcmp(char *s1, char *s2);
char	*ft_join_free(char *s1, char *s2);

// common_files/utils/ft_token_utils.c
t_token	*ft_add_token(char *str, int type);
t_token	*ft_getlast(t_token *lst);
void	ft_token_addback(t_token **lst, t_token *new);
void	ft_free_token(t_token **t);
void	ft_delete_next_token(t_token **t);
void	ft_delete_prev_token(t_token **t);
void	ft_remove_tok(t_token **list);


// common_files/utils/ft_token_utils2.c
void	ft_position_it(t_token **lst);
void	ft_print_utils(int type);
void	ft_print_token(t_token *t);
void	ft_print_token_str(t_token *t);

// -------------------------------------- //
// ---------> The Lexer stage <--------- //
// ------------------------------------ //

// common_files/lexer/ft_check_hdoc.c
int		ft_valid_hd_delim(t_token *lst);
int		ft_check_hdoc(t_token *lst);
char	*ft_heredoc(char *del);
char	*ft_hdoc_tofd(char *str);

// common_files/lexer/ft_check_quotes.c
int		ft_valid_quote(t_token *t);
void	ft_merge_words(t_token **lst);

// common_files/lexer/ft_check_redirections.c
int		ft_check_operators(t_token *lst);
int		if_valid_re_floower(t_token *node);
int		ft_check_redirections(t_token *lst);
int		ft__opperators(t_token *lst);

// common_files/lexer/ft_main_lexer.c
void	ft_main_lexer(t_token *lst);

// common_files/lexer/ft_opperators.c
int		ft_operator(t_token *l);
int		ft_opperators(t_token *lst);

// common_files/lexer/ft_simple_command.c
void	ft_build_scomm(t_token **lst);
void	ft_join_space(t_token **lst);
void	ft_join_wq(t_token **lst);

// common_files/lexer/ft_redirections.c
int		ft_isredirection(t_token *l);
void	ft_detect_files(t_token **lst);
int		ft_isvalidred(t_token *lst);

#endif