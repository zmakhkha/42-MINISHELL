/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:02:26 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/17 00:47:58 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include<libc.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_isvalidparet(char *str)
{
    int i;
    int open;

    i = -1;
    open = 0;
    while(str[++i])
    {
        if (str[i] == '(')
            open++;
        if (str[i] == ')')
            open--;
    }
    if (!open)
        return (1);
    return (0);
}

int main()
{
    char *s = "sdjbad((()))";
    printf("hooo yaaaa %d", ft_isvalidparet(s));
    char a = ft_strchr(s, ')');
}