/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:02:26 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/06/30 12:48:40 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libc.h>
#include "header.h"
#include <fcntl.h>

// to transform a heredoc to an input file
int	main(void)
{
	int	a;

	a = fork();
	if (a == 0)
	{
	}
	else
	{
		printf("\n\n salina\n");
	}
	system ("leaks a.out");
	exit();
}
