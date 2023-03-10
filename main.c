/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:21 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/10 16:28:04 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"
#include<libc.h>
#include <readline/readline.h>
#include <readline/history.h>
int main() {
//   char* input;
//   input = "ababaa";
//   while (1) {
//     usleep(100);
//     // input = readline(">> ");
//     if (input == NULL) {
//       printf("\n");
//       break;
//     }
//     if (ft_strlen(input) > 0) {
//     //   ft_add_history(input);
//       printf("You entered: %s \n", input);
//     }
//     // free(input);
//   }
//   return 0;
printf( "%s\n", readline( "test> " ) );
    return 0;
}