# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fooxcoder <fooxcoder@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:57:35 by ayel-fil          #+#    #+#              #
#    Updated: 2023/05/20 07:30:59 by fooxcoder        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
NAME = libft.a

CFLAGS = -Wall -Wextra

RM = rm -f

CFILES =	ft_isalpha.c ft_printf.c ft_substr_gnl.c \
         	ft_put_address.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putnbr_u.c\
         	ft_putstr.c ft_handler.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
			ft_isprint.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
			ft_strlen.c ft_memcpy.c ft_strdup.c ft_toupper.c ft_bzero.c\
			ft_memchr.c ft_memmove.c ft_strlcat.c ft_strrchr.c ft_memcmp.c\
			ft_memset.c ft_strlcpy.c ft_tolower.c ft_strchr.c ft_atoi.c\
			ft_strtrim.c ft_strnstr.c ft_substr.c  ft_calloc.c ft_strjoin.c\
			ft_split.c ft_itoa.c ft_putnbr_fd.c ft_striteri.c ft_strncmp.c\
			ft_strmapi.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
			ft_lstmap_bonus.c ft_strcmp.c ft_isspace.c ft_atof.c\
			ft_check_integer.c get_next_line.c get_next_line_bonus.c\
			ft_p2darray.c

OBJ = $(CFILES:.c=.o)


AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJ) libft.h
	@$(AR)  $(NAME) $(OBJ)
	@echo "$(NAME): $(GREEN)The libft was successfully built.$(RESET)"


%.o : %.c libft.h
	@$(CC) $(CFLAGS) -c  $<

clean:
	@$(RM) $(OBJ)
	
fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"


re: fclean all

.PHONY: clean fclean re all bonus
