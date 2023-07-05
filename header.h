/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:13:57 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/05 14:06:14 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libs/includes.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

// static void *_malloc(size_t c, char *file, int line)
// {
// 	void *p = malloc(c);
// 	printf("MALC: %p, LINE = %i, FILE = %s\n", p, line, file);
// 	return (p);
// }

// static void _free(void* c, char *file, int line)
// {
// 	printf("FREE: %p, LINE = %i, FILE = %s\n", c, line, file);
// 	return (free(c));
// }

// #define malloc(c) _malloc(c, __FILE__, __LINE__)
// #define free(c) _free(c, __FILE__, __LINE__)

# define EXLUDE "` @ # % ^ + = \ ;"
# define H_PATH "/tmp/.minishell_history"
# define H_DOCP "/Users/zmakhkha/Desktop/"
# define SUCC 0
# define ERR 1

typedef struct s_gobvar
{
	int				g_status;
	int				g_ctrl_c;
	int				g_ctrl_s;
}					t_global;

t_global			g_glob;
// -------> Tokens enumeration <------- //

enum
{
	Empty,
	PIPE,
	AND,
	OR,
	WORD,
	FILE_,
	SPACE_,
	SUBSHELL,
	AMP,
	RE_IN,
	RE_OUT,
	HDOC,
	APPEND,
	W_CARD,
	DIGITE
};

void				detect(void *res);
void				ft_handle_child(int signal);

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
}					t_token;

// -------------------------------------- //
// -------> The tokenizer stage <------- //
// ------------------------------------ //

// common_files/tokenizer/ft_string_utils.c
void				ft_word(char *str, t_token **lst, int *a, int *b);
void				d_quotes(char *str, t_token **lst, int *a, int *b);
void				s_quotes(char *str, t_token **lst, int *a, int *b);
void				ft_operators(char *str, t_token **lst, int *a, int *b);
void				ft__operators(char *str, t_token **lst, int *a, int *b);

// common_files/tokenizer/ft_string_utils2.c
void				ft_space_(char *str, t_token **lst, int *a, int *b);
void				ft_digits(char *str, t_token **lst, int *a, int *b);
int					ft_operators2(char *str, t_token **lst, int *a, int *b);
int					ft_operators3(char *str, t_token **lst, int *a, int *b);
void				ft_prt(char *str, t_token **lst, int *a, int *b);
int					if_validp(char *str);

// common_files/tokenizer/ft_string_utils3.c
int					ft_voperator(char *str, char op);
int					ft_validouble(char *str, char op);
char				*ft_toktostr(t_token *src);

// common_files/tokenizer/ft_string_utils4.c
int					ft_forbidden(char *str);
int					ft_is_operators4(char c);
void				ft_operators4(char *str, t_token **lst, int *a, int *b);

// common_files/tokenizer/ft_token_utils.c
void				ft__strtok(char *str, t_token **lst, int *a, int *b);
t_token				*ft_strtok(char *str);
t_token				*ft_main_token(t_token *lst);

// common_files/tokenizer/ft_valid_utils.c
int					ft_is_operator(char c);
int					ft_is_moperator(char c);
int					ft_is_operator4(char c);
int					ft_is_operator2(char c);
int					ft_is_quote(char c);

// common_files/tokenizer/ft_valid_utils2.c
void				ft_exit(char *c, int s);
int					ft_valid_word(char c);
int					ft_is_valid_comm2(char c);
int					ft_is_whitespace_(char c);
int					ft_is_operator3(char c);

// -------------------------------------- //
// --------------> Utils <-------------- //
// ------------------------------------ //

// common_files/utils/ft_history_utils.c
int					ft_add_history(char *str);
void				ft_print(char *a);

// common_files/utils/ft_prompt.c
void				ft_free_env(t_env **env);
void				ft_free_2dstr(char **str);
void				ft_prompt(char **env);

// common_files/utils/ft_strings.c
int					ft_strcmplen(char *s1, char *s2);
char				*ft_join_free(char *s1, char *s2);

// common_files/utils/ft_token_utils.c
t_token				*ft_add_token(char *str, int type);
t_token				*ft_getlast(t_token *lst);
t_token				*ft_getfirst(t_token *lst);
void				ft_token_addback(t_token **lst, t_token *new);
void				ft_free_token(t_token **t);

// common_files/utils/ft_token_utils2.c
void				ft_position_it(t_token **lst);
void				ft_print_utils(int type);
// void	ft_print_token(t_token *t);
// void	ft_print_token_str(t_token *t);
void				ft_remove_tok(t_token **list, t_token *node);
void				ft_swap(t_token *lst);

// -------------------------------------- //
// ---------> The Lexer stage <--------- //
// ------------------------------------ //

// common_files/lexer/ft_check_hdoc.c
int					ft_valid_hd_delim(t_token *lst);
int					ft_check_hdoc(t_token *lst);
char				*ft_heredoc(char *del);
char				*ft_hdoc_tofd(char *str, int type, t_env *env_list);

// common_files/lexer/ft_check_quotes.c
int					ft_valid_quote(t_token *t);
void				ft_merge_words(t_token **lst);

// common_files/lexer/ft_check_redirections.c
int					ft_check_operators(t_token *lst);
int					if_valid_re_floower(t_token *node);
int					ft_check_redirections(t_token *lst);
int					ft__opperators(t_token *lst);

// common_files/lexer/ft_lexer_utils.c
void				ft_lasterr(t_token *lst);
void				ft_singleerr(t_token *lst);
void				ft_checksyntax(t_token *lst);
void				ft_checkfiles(t_token *lst);
void				ft_mergeword_num(t_token **list);

// common_files/lexer/ft_main_lexer.c
void				ft_mergewords(t_token **list);
void				ft_merge_sp(t_token **list);

void				ft_main_lexer(t_token *lst);

// common_files/lexer/ft_opperators.c
int					ft_operator(t_token *l);
int					ft_opperators(t_token *lst);
int					ft_subshells(t_token *lst);
void				ft_detect_op(t_token **list);

// common_files/lexer/ft_simple_command.c
void				ft_build_scomm(t_token **lst);
void				ft_join_SPACE_(t_token **lst);
void				ft_join_wq(t_token **lst);

// common_files/lexer/ft_redirections.c
int					ft_isredirection(t_token *l);
void				ft_detect_files(t_token **lst);
int					ft_isvalidred(t_token *lst);

// common_files/lexer/ft_syntax_errors.c

int					ft_loperators(t_token *lst);
int					ft_isbigoperators(t_token *lst);
int					ft_isforbidden(t_token *lst);
void				ft_check_op(t_token *lst);
void				ft_operrors(t_token *lst);

// common_files/lexer/ft_syntax_errors2.c

void				ft_succop(t_token *lst);
void				ft_sub_red(t_token *lst);
void				ft_syntaxerr(t_token *lst);
void				ft_op_space_(t_token **list);

// common_files/lexer/ft_red_utils.c
void				ft_swap_red(t_token **list);
void				ft_swap_red2(t_token **list);
void				ft_swap_red3(t_token **list);

// common_files/lexer/ft_mergeutils.c
void				ft_rm_space_(t_token **list);
void				ft_merge_sp(t_token **list);
void				ft_merge_dig(t_token **list);
void				ft_word_dig(t_token **list);

// common_files/lexer/ft_fdutils.c
void				ft_fd_file(t_token **list);
void				ft_readfd(t_token **list);

// common_files/lexer/ft_errors.c
void				ft_three(t_token *lst);
char				*ft_twotoone(char **table);
int					ft_valid_hd_delim(t_token *lst);

// -------------------------------------- //
// ----------> The AST stage <---------- //
// ------------------------------------ //

// common_files/ast/ft_ops_utils.c

int					ft_isthere_bop(t_token *lst);
void				ft_make_bigops(t_token **list);
int					ft_isthere_pipe(t_token *lst);
t_token				*ft_make_pipes(t_token **list);
void				ft_pipe_nodes(t_token **list);

// common_files/ast/ft_ast_utils.c

int					ft_lstlen(t_token *lst);
void				ft_exe_tree(t_token *list, t_env *env_list);
t_token				*ft_pop(t_token **list);
void				ft_free_tree(t_token **list);

// common_files/ast/ft_main_ast.c
void				ft_main_ast(t_token **list, t_env **env_list);

// common_files/ast/ft_leafs_utils.c
t_token				*ft_makenull(void);
t_token				*ft_make_leafs(t_token **list);
void				ft_leaf_nodes(t_token **list);

//--------------> The HDOC TO IN stage <---------------//

// common_files/ast/ft_asthdoc.c

char				*ft_get_path(char *del, int type, t_env **env_list);
void				ft_hdoc_to_file(t_token **list, t_env **env_list);
void				ft_hdocontree(t_token **list, t_env **env_list);

// common_files/ast/ft_asthdoc2.c
char				*ft_rmsq2(char *str, int len, char c);
char				*ft_rmsq1(char *str);
char				*ft_exp1(char *str);
char				*ft_rmsq_(char *str);

//--------------> The SUB TO TREE stage <---------------//

void				ft_sub_ast(t_token **list);
void				ft_subtotree(t_token **list);

//--------------------------------------------------//
//--------------> execution > part <---------------//
//------------------------------------------------//

# define CNF "command not found"
# define CD_ER "cd: error retrieving current directory: getcwd: cannot access\
				parent directories: No such file or directory"
# define VALUE_PATH "/Users/ayel-fil/.docker/bin:/usr/gnu/bin:/usr/local/bi\
n:/bin:/usr/bin:.:/Users/ayel-fil/.fzf/bin"
# define EXIT_ERR "exit: too many arguments"

typedef struct s_pipex
{
	int				pipefd[2];
	int				status;
	pid_t			pid_1;
	pid_t			pid_2;
}					t_pipex;

typedef struct s_cmd
{
	char			*name;
	char			**args;
	char			**paths;
	char			*path_cmd;
	char			**env;
	bool			relative_or_binary;
}					t_cmd;

enum				e_fd
{
	ER = STDERR_FILENO,
	IN = STDIN_FILENO,
	OUT = STDOUT_FILENO,
	EXECVE
};

/* src/error.c */
int					ft_error(char *msg, char *cmd, int exit_status);
int					ft_protect(int fd, char *str, char *msg);
void				ft_perror(char *err_msg1, char *err_msg2);
int					ft_exit_pipe(t_pipex *px);
/* src/execution */
int					ft_execution(t_token *t, t_env *env_list);

/* src/env/ */
t_env				*set_env(char **env);
char				*get_value(char *key, t_env *env);
void				change_env(char *key, char *value, t_env **env);
char				**list_to_array(t_env *env);
void				add_env_node(char *key, char *value, t_env **env_list);
/* src/builtin */
bool				is_builtin(char **commad);
int					execute_env(t_env *env_list);
int					execute_builtin(char **list, t_env *env);
int					execute_cd(char **cmd, t_env **env_list);
int					execute_echo(char **cmd);
int					execute_export(char **list, t_env **env_list);
int					execute_unset(char **list, t_env **env_list);
int					execute_pwd(t_env **env);
int					declare_env(t_env **env_list);
int					parse_arguments(char *arg, char **key, char **value);
int					check_if_valid(char *arg);
int					execute_exit(char **list);
char				**ft_sort_env(char **env);

/* src/run_cmd */
t_cmd				ft_init_cmd(char **args, char **env);
char				*set_cmd_path(t_cmd *cmd);
bool				ft_check_relative_or_binary(t_cmd *cmd);
/* src/process/child.c */
int					ft_child_process(t_cmd *cmd, t_env *env);

/* src/run_cmd/ */
int					execute_logical_op(t_token *list, t_env *env);
int					execute_command(char **args, t_env *env);
int					execute_pipe(t_token *list, t_env *env);
int					execute_re(t_token *list, t_env *env);

/* src/run_cmd/ */
void				child1_handler(t_pipex *pipex, t_token *list, t_env *env);
void				child2_handler(t_pipex *pipex, t_token *list, t_env *env);
/* src/utils/ */
int					run_append(t_token *list, t_env *env);
int					run_re_in(t_token *list, t_env *env);
int					run_re_out(t_token *list, t_env *env);

//-----------------------------------------------------//
//--------------> The expanding stage <---------------//
//---------------------------------------------------//

typedef struct t_str
{
	char			*str;
	struct t_str	*prev;
}					t_str;

# define LEFT -1
# define RIGHT -2
# define MIDL -3
# define MULT -4
# define ALONE -5

// expanding/ft_dir_lst.c

t_str				*ft_dirfiles(t_env *env_list);

// expanding/ft_exp_utils.c

char				*ft_join_freel(char *s1, char *s2, int len);
char				*ft__rmsq(char *str, int i, int len, int c);
char				*ft_rmsq(char *str);
char				*ft__rmsq2(char *str, int len, char c);
void				ft_merge_all(t_token **list);

// common_files/expanding/ft_exp_utils1.c

int					ft_isquote(char *str);
char				**ft_format(char *str);
void				ft_strrep(char *str, char a, char b);
t_str				*ft_strmkcpy(t_str *src);
t_str				*ft_matching(t_str *src, char *str);

// expanding/ft_left_right.c

int					ft_count_lmatching(t_str *src, char *cnd);
t_str				*ft_wc_left(t_str *src, char *cnd);
int					ft_count_rmatching(t_str *src, char *cnd);
t_str				*ft_wc_right(t_str *src, char *cnd);
int					ft_count(char *str);

// expanding/ft_lst_utils.c

t_str				*ft_add_str(char *str);
void				ft_str_addback(t_str **lst, t_str *new);
void				ft_free_str(t_str **t);

// expanding/ft_main_exp.c

char				*ft_expand(char *str, t_env *env);
char				*ft_rm__exp(char *str, t_env *env, char *res, int i);
char				*ft_rm_exp(char *str, t_env *env);
int					ft_isquote(char *str);
char				**ft_main_exp(char *str, t_env *env);

// expanding/ft_mult.c

t_str				*ft_middle(t_str *src, char *cnd);
t_str				*ft_multi(t_str *src, char *cnd);

// expanding/ft_wild_card.c

char				*ft_strnstr1(const char *haystack, const char *needle,
						size_t len);
t_str				*ft_matching(t_str *src, char *str);
char				*ft_main_wc(char *str, t_env *env_list);

//--------------> The Signals stage <---------------//

void				ft_child_handler(int signal);
void				ft_main_handler(int signal);
void				ft_signal_child(void);
void				ft_signal_main(void);
void				ft_signal_ignore(void);
char				**ft_onesplit(char const *s, char c);

# define QUOTE -10

// t_token				*ft_strtok1(char *str);

//--------------> The export built-in stage <---------------//
// execution/src/builtin/export/utils.c

# define APP -10
# define REP -20

// void				ft_format_print(t_env *env);
// void				ft_makekey_value(t_token *lst, t_env **env);
void				ft_export_it(t_token *list, t_env **env);
void				ft_merge_num_word(t_token **list);
void				ft_format_print(t_env *env);
void				ft_with_quotes(t_token *lst, t_env *env);
void				ft_no_qoute(t_token *lst, t_env *env);
void				ft_app_exp(t_token *lst, t_env *env);

// execution/src/builtin/export/utils2.c
int					ft_containequl(char *str);
void				ft_mergewordspace(t_token **list);
char				**ft_devide(char *r, char del);
int					ft_isvalidkey(char *str);
void				ft_addnode(t_token *lst, t_env **env);

// execution/src/builtin/export/utils3.c
void				ft_rep_exp(t_token *lst, t_env *env);
int					ft_detect(t_token *lst, t_env *env);
void				ft_parse_export(t_token *lst, t_env *env);
void				ft_print_exp(t_env *env);
void				ft_handle_one(char *s, t_env **env);

// execution/src/builtin/export/utils4.c
char				**ft_env_to_char(t_env *env);
void				ft_sort_char(char **table);
void				ft_sort_print_env(t_env *env);
t_env				*ft_make_envcpy(t_env *env);
int					ft_envlen(t_env *env);

#endif
