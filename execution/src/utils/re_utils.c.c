/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_utils.c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-fil <ayel-fil@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 02:12:42 by ayel-fil          #+#    #+#             */
/*   Updated: 2023/06/23 03:47:10 by ayel-fil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header.h"

int	execute_append(t_token *list, t_env *env)
{
	 int status = EXIT_SUCCESS;
    int fd;

    if (!list || !list->str) {
        return EXIT_FAILURE;
    }

    fd = open(list->str, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening append file");
        return EXIT_FAILURE;
    }

    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("Error redirecting output to append file");
        status = EXIT_FAILURE;
    }

    close(fd);

    status = ft_execution(list->right, env);

    return status;
}
