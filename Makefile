# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#              #
#    Updated: 2023/05/06 07:41:11 by zmakhkha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M_NAME = minishell
FT_PATH = libft/libft.a
SRC_MN =	common_files/lexer/ft_check_hdoc.c \
			common_files/lexer/ft_opperators.c \
			common_files/lexer/ft_main_lexer.c \
			common_files/lexer/ft_redirections.c \
			common_files/lexer/ft_simple_command.c \
			common_files/lexer/ft_check_redirections.c \
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
			common_files/utils/ft_strings.c \
			main.c

OBJ = $(SRC_MN:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra  -fsanitize=address -g

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