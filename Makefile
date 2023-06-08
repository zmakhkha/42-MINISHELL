# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/06/06 14:36:08 by ayel-fil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = minishell
LIBS = libs/libs.a
LIBS_DIR = libs
CFLAGS = -Wall -Werror -Wextra -Wunused-function  -g #-fsanitize=address
LDFLAGS = -lreadline #-fsanitize=address

HEADERS = header.h

#parsing part:
=======
#    Updated: 2023/05/30 18:31:16 by zmakhkha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M_NAME = minishell
FT_PATH = libft/libft.a
>>>>>>> Implemented heredoc logic
SRC_MN =	main.c \
			common_files/ast/ft_ast_utils.c \
			common_files/ast/ft_leafs_utils.c \
			common_files/ast/ft_main_ast.c \
			common_files/ast/ft_ops_utils.c \
			common_files/lexer/ft_errors.c \
			common_files/lexer/ft_check_hdoc.c \
			common_files/lexer/ft_check_redirections.c \
			common_files/lexer/ft_fdutils.c \
			common_files/lexer/ft_main_lexer.c \
			common_files/lexer/ft_mergeutils.c \
			common_files/lexer/ft_operators.c \
			common_files/lexer/ft_operators2.c \
			common_files/lexer/ft_red_utils.c \
			common_files/lexer/ft_redirections.c \
			common_files/lexer/ft_syntax_errors.c \
			common_files/lexer/ft_syntax_errors2.c \
			common_files/tokenizer/ft_valid_utils.c \
			common_files/tokenizer/ft_string_utils.c \
			common_files/tokenizer/ft_string_utils4.c \
			common_files/tokenizer/ft_string_utils3.c \
			common_files/tokenizer/ft_string_utils2.c \
			common_files/tokenizer/ft_valid_utils2.c \
			common_files/tokenizer/ft_main_token.c \
			common_files/utils/ft_token_utils.c \
			common_files/utils/ft_token_utils2.c \
			common_files/utils/ft_history_utils.c \
			common_files/utils/ft_prompt.c \
			common_files/utils/ft_strings.c

<<<<<<< HEAD
#execution part:
SRC_EX = execution/execute.c execution/src/env/env.c execution/src/error.c\
		 execution/src//utils/builtin_utils.c execution/src/builtin/cd.c\
		 execution/src/builtin/pwd.c execution/src//utils/env_utils.c\
		 execution/src/run_cmd/exe.c
#create .OBJ files:
SRC = $(SRC_MN) $(SRC_EX)
OBJ = $(SRC:.c=.o)
=======
OBJ = $(SRC_MN:.c=.o)
>>>>>>> Implemented heredoc logic

CC = cc

CFLAGS = -Wall -Werror -Wextra -Wunused-function  -g #-fsanitize=address

all: $(M_NAME)

$(M_NAME) : $(OBJ)
	$(CC)  $(CFLAGS) $(SRC_MN) $(FT_PATH) -o $(M_NAME) -lreadline
%.o:%.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(M_NAME)

re	: fclean	all

wq	: re	clean 
.PHONY: all clean fclean re 