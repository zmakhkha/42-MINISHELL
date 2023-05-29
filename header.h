/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:13:57 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/29 02:16:42 by ayel-fil         ###   ########.fr       */
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

# include "libs/includes.h"

# define EXLUDE "` @ # % ^ + = \ ;"
# define H_PATH "/tmp/.minishell_history"
# define H_DOCP "/tmp/"
# define SUCC 0
# define ERR 1

int	g_status;
// -------> Tokens enumeration <------- //

enum
{
	Empty,
	PIPE,
	AND,
	OR,
	WORD,
	FILE_,
	SPACE,
	SUBSHELL,
	AMP,
	RE_IN,
	RE_OUT,
	HDOC,
	APPEND,
	W_CARD,
	DIGITE
};

// -------------------------------------- //
// ----------> Command struct <--------- //
// ------------------------------------ //

typedef struct s_command
{
	char			**str;
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
	struct s_token	*left;
	struct s_token	*right;
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
void	d_quotes(char *str, t_token **lst, int *a, int *b);
void	s_quotes(char *str, t_token **lst, int *a, int *b);
void	ft_operators(char *str, t_token **lst, int *a, int *b);
void	ft__operators(char *str, t_token **lst, int *a, int *b);

// common_files/tokenizer/ft_string_utils2.c
void	ft_space(char *str, t_token **lst, int *a, int *b);
void	ft_digits(char *str, t_token **lst, int *a, int *b);
int		ft_operators2(char *str, t_token **lst, int *a, int *b);
int		ft_operators3(char *str, t_token **lst, int *a, int *b);
void	ft_prt(char *str, t_token **lst, int *a, int *b);
int		if_validp(char *str);

// common_files/tokenizer/ft_string_utils3.c
int		ft_voperator(char*str, char op);
int		ft_validouble(char *str, char op);

// common_files/tokenizer/ft_string_utils4.c
int		ft_forbidden(char *str);
int		ft_is_operators4(char c);
void	ft_operators4(char *str, t_token **lst, int *a, int *b);

// common_files/tokenizer/ft_token_utils.c
void	ft__strtok(char *str, t_token **lst, int *a, int *b);
t_token	*ft_strtok(char *str);
t_token	*ft_main_token(t_token *lst);

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
int		ft_strcmplen(char *s1, char *s2);
char	*ft_join_free(char *s1, char *s2);

// common_files/utils/ft_token_utils.c
t_token	*ft_add_token(char *str, int type);
t_token	*ft_getlast(t_token *lst);
t_token	*ft_getfirst(t_token *lst);
void	ft_token_addback(t_token **lst, t_token *new);
void	ft_free_token(t_token **t);

// common_files/utils/ft_token_utils2.c
void	ft_position_it(t_token **lst);
void	ft_print_utils(int type);
// void	ft_print_token(t_token *t);
// void	ft_print_token_str(t_token *t);
void	ft_remove_tok(t_token **list, t_token *node);
void	ft_swap(t_token *lst);

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
void	ft_merge_sp(t_token **list);

void	ft_main_lexer(t_token *lst);

// common_files/lexer/ft_opperators.c
int		ft_operator(t_token *l);
int		ft_opperators(t_token *lst);
int		ft_subshells(t_token *lst);
void	ft_detect_op(t_token **list);

// common_files/lexer/ft_simple_command.c
void	ft_build_scomm(t_token **lst);
void	ft_join_space(t_token **lst);
void	ft_join_wq(t_token **lst);

// common_files/lexer/ft_redirections.c
int		ft_isredirection(t_token *l);
void	ft_detect_files(t_token **lst);
int		ft_isvalidred(t_token *lst);

// common_files/lexer/ft_syntax_errors.c

int		ft_loperators(t_token *lst);
int		ft_isbigoperators(t_token *lst);
int		ft_isforbidden(t_token *lst);
void	ft_check_op(t_token *lst);
void	ft_operrors(t_token *lst);

// common_files/lexer/ft_syntax_errors2.c

void	ft_succop(t_token *lst);
void	ft_sub_red(t_token *lst);
void	ft_syntaxerr(t_token *lst);
void	ft_op_space(t_token **list);

// common_files/lexer/ft_red_utils.c
void	ft_swap_red(t_token **list);
void	ft_swap_red2(t_token **list);
void	ft_swap_red3(t_token **list);

// common_files/lexer/ft_mergeutils.c
void	ft_rm_space(t_token **list);
void	ft_merge_sp(t_token **list);
void	ft_merge_dig(t_token **list);
void	ft_word_dig(t_token **list);

// common_files/lexer/ft_fdutils.c
void	ft_fd_file(t_token **list);
void	ft_readfd(t_token **list);

// common_files/lexer/ft_errors.c
void	ft_three(t_token *lst);

// -------------------------------------- //
// ----------> The AST stage <---------- //
// ------------------------------------ //

// common_files/ast/ft_ops_utils.c

int		ft_isthere_bop(t_token *lst);
void	ft_make_bigops(t_token **list);
int		ft_isthere_pipe(t_token *lst);
t_token	*ft_make_pipes(t_token **list);
void	ft_pipe_nodes(t_token **list);

// common_files/ast/ft_ast_utils.c

int		ft_lstlen(t_token *lst);
void	ft_print_tree(t_token *list);
t_token	*ft_pop(t_token **list);
void	ft_free_tree(t_token **list);

// common_files/ast/ft_main_ast.c
void	ft_main_ast(t_token **list);

// common_files/ast/ft_leafs_utils.c
t_token	*ft_makenull(void);
t_token	*ft_make_leafs(t_token **list);
void	ft_leaf_nodes(t_token **list);

#endif
