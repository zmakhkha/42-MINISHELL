# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#              #
#    Updated: 2023/03/18 13:30:35 by zmakhkha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M_NAME = minishell
FT_PATH = libft/libft.a
SRC_MN =	common_files/ft_prompt.c \
			common_files/ft_valid_utils.c \
			common_files/ft_valid_utils2.c \
			common_files/token_utils.c \
			common_files/ft_string_utils.c \
			common_files/ft_string_utils2.c \
			common_files/ft_string_utils3.c \
			common_files/ft_string_utils4.c \
			main.c

OBJ = $(SRC_MN:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra # -fsanitize=address

all: $(M_NAME)

$(M_NAME) : $(OBJ)
	$(CC)  $(CFLAGS) $(SRC_MN) $(FT_PATH) -o $(M_NAME) -lreadline -g
%.o:%.c header.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(M_NAME)

re	: fclean	all

wq	: re	clean 
.PHONY: all clean fclean re 