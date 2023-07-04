/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:02:26 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/07/04 19:20:05 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main()
{
    int a;
    int p[2];
    char    *tmp;

    while(1)
    {
        
    tmp  = calloc(10000, sizeof(char));
    if (pipe(p) == -1)
        perror("heredoc : ");
    a = -50;
    a = fork();
    if (!a)
    {
           tmp = ft_strdup("hahsdasdfsadfasdfsdasdafa");
           close(p[0]);
           write(p[1], tmp, ft_strlen(tmp));
           close(p[1]);
           exit(0);
    }
    waitpid(-1, NULL, 0);
    close (p[1]);
    read(p[0], tmp, 10000);
    puts(tmp);
    }
}