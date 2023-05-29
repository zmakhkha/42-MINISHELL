# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:57:35 by ayel-fil          #+#    #+#              #
#    Updated: 2023/05/24 05:50:12 by ayel-fil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = libs.a

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar -rcs

#HEADERS:

Includes =  GNL/gnl.h print_fd/print_fd.h Add_functions/add.h includes.h\
			linkedlist/linkedlist.h libc_function/lib_c.h ft_printf/ft_printf.h\
			Additional/additional.h check_is/check_is.h define.h
 #Cfiles:
LIB_C =  libc_function/ft_strnstr.c libc_function/ft_strlcpy.c\
		 libc_function/ft_strlen.c libc_function/ft_memcmp.c\
		 libc_function/ft_strchr.c libc_function/ft_bzero.c\
		 libc_function/ft_memcpy.c libc_function/ft_toupper.c\
		 libc_function/ft_strrchr.c libc_function/ft_memchr.c\
		 libc_function/ft_memset.c libc_function/ft_strncmp.c\
		 libc_function/ft_memmove.c libc_function/ft_strlcat.c\
		 libc_function/ft_calloc.c libc_function/ft_strdup.c\
		 libc_function/ft_atoi.c libc_function/ft_itoa.c\
		 libc_function/ft_tolower.c libc_function/ft_strcmp.c

GNL = 	GNL/ft_substr_gnl.c GNL/get_next_line.c GNL/get_next_line_bonus.c

CHECK =	 check_is/ft_isalpha.c check_is/ft_isdigit.c check_is/ft_isalnum.c \
		 check_is/ft_isascii.c check_is/ft_isprint.c check_is/ft_isspace.c

PRINTF = ft_printf/ft_printf.c ft_printf/ft_put_address.c ft_printf/ft_puthex.c\
		ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putnbr_u.c \
		ft_printf/ft_putstr.c ft_printf/ft_handler.c

LINKED =   linkedlist/ft_lstadd_front_bonus.c linkedlist/ft_lstdelone_bonus.c\
 		   linkedlist/ft_lstadd_back_bonus.c linkedlist/ft_lstmap_bonus.c\
 		   linkedlist/ft_lstclear_bonus.c linkedlist/ft_lstiter_bonus.c\
 		   linkedlist/ft_lstlast_bonus.c linkedlist/ft_lstsize_bonus.c\
 		   linkedlist/ft_lstnew_bonus.c

ADD =	Additional/ft_atof.c Additional/ft_p2darray.c Additional/ft_strcmpl.c

ADD_F = Add_functions/ft_striteri.c Add_functions/ft_strjoin.c\
  		Add_functions/ft_split.c Add_functions/ft_substr.c\
		Add_functions/ft_strmapi.c Add_functions/ft_strtrim.c

FD = print_fd/ft_putchar_fd.c print_fd/ft_putstr_fd.c print_fd/ft_putnbr_fd.c\
     print_fd/ft_putendl_fd.c

#OBJ_FILES
OBJ_LIB_C = $(LIB_C:.c=.o)
OBJ_GNL = $(GNL:.c=.o)
OBJ_CHECK = $(CHECK:.c=.o)
OBJ_PRINTF = $(PRINTF:.c=.o)
OBJ_LINKED = $(LINKED:.c=.o)
OBJ_ADD = $(ADD:.c=.o)
OBJ_ADD_F = $(ADD_F:.c=.o)
OBJ_FD = $(FD:.c=.o)
OBJ = $(OBJ_LIB_C) $(OBJ_GNL) $(OBJ_CHECK) $(OBJ_PRINTF) $(OBJ_LINKED)\
	  $(OBJ_ADD) $(OBJ_ADD_F) $(OBJ_FD)


#targets:

all: $(NAME)

$(NAME): $(OBJ) $(Includes)
	@$(AR)  $(NAME) $(OBJ)
	@echo "$(NAME): $(GREEN)successfully built.$(RESET)"


%.o : %.c  $(Includes)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	
fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"


re: fclean all

.PHONY: clean fclean re all bonus
