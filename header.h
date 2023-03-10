#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

// common_files/ft_prompt.c
void    ft_add_history(char *tmp);
char    *ft_readline();
void	ft_print(char *a);



#endif