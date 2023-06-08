# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#              #
#    Updated: 2023/06/06 15:18:29 by ayel-fil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = minishell
LIBS = libs/libs.a
LIBS_DIR = libs
CFLAGS = -Wall -Werror -Wextra -Wunused-function  -g -fsanitize=address
LDFLAGS = -lreadline -fsanitize=address

HEADERS = header.h

#parsing part:
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

#execution part:
SRC_EX = execution/execute.c execution/src/env/env.c execution/src/error.c\
		 execution/src//utils/builtin_utils.c execution/src/builtin/cd.c\
		 execution/src/builtin/pwd.c execution/src//utils/env_utils.c\
		 execution/src/run_cmd/exe.c
#create .OBJ files:
SRC = $(SRC_MN) $(SRC_EX)
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME) : $(OBJ) $(HEADERS) $(LIBS)
	@$(CC) $(LDFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created successfully.$(RESET)"

library:
	@make -C $(LIBS_DIR)

%.o: %.c | library
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@make -C $(LIBS_DIR) clean
	@rm -rf $(OBJ)
	@echo "$(NAME): $(RED)The object files were deleted.$(RESET)"

fclean: clean
	@make -C $(LIBS_DIR) fclean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED) The executable file was deleted.$(RESET)"

re: fclean all
