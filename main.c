/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:47:47 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/13 13:43:47 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *env[])
{
	char	*path;	
	int		pipefd[2];
	pid_t	cpid;

	if (ac == 5)
	{
		path = ft_getenv(env, "PATH");
		if (path == NULL || ft_strlen(path) == 0)
			print_and_exit("invalid path\n");
		perror_and_exit(pipe(pipefd), "pipe");
		perror_and_exit(cpid = fork(), "fork");
		if (cpid == 0)
			ft_exec_child(av, env, pipefd);
		else
			ft_exec_parent(av, env, pipefd);
	}
	return (0);
}
