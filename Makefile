M_NAME = minishell
FT_PATH = libft/libft.a
SRC_MN =	common_files/ft_prompt.c \
			main.c

OBJ = $(SRC_MN:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(M_NAME)

$(M_NAME) : $(OBJ)
	$(CC)  $(CFLAGS) $(OBJ) $(FT_PATH) -o $(M_NAME)

%.o:%.c header.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(M_NAME)

re	: fclean	all

.PHONY: all clean fclean re 