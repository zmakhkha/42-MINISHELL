/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:47:50 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/11 13:01:16 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_echo(char **cmd)
{
	int i = 1;
	bool newline;

	newline = true;
	while (cmd[i] != NULL && strcmp(cmd[i], "-n") == 0)
	{
		newline = false;
		i++;
	}

	while (cmd[i] != NULL)
	{
		printf("%s", cmd[i]);
		if (cmd[i + 1] != NULL)
			printf(" ");
		i++;
	}

	if (newline)
		printf("\n");

	return (0);
}