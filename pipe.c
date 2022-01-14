/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:24:06 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/13 14:16:34 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_child(char *av[], char *env[], int pipefd[2])
{
	int		infd;
	char	**newcmd;
	char	*path;

	infd = open(av[1], O_RDONLY);
	perror_and_exit(infd, "error");
	newcmd = ft_split(av[2], ' ');
	path = find_cmd_path(ft_getenv(env, "PATH"), newcmd[0]);
	if (path == NULL)
		perror_and_exit(-1, "first cmd");
	perror_and_exit(close(pipefd[0]), "close");
	perror_and_exit(dup2(infd, 0), "dup2");
	perror_and_exit(dup2(pipefd[1], 1), "dup2");
	perror_and_exit(execve(path, newcmd, env), "execve");
}

void	ft_exec_parent(char *av[], char *env[], int pipefd[2])
{
	int		outfd;
	char	**newcmd;
	char	*path;

	outfd = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
	perror_and_exit(outfd, "error");
	newcmd = ft_split(av[3], ' ');
	path = find_cmd_path(ft_getenv(env, "PATH"), newcmd[0]);
	if (path == NULL)
		perror_and_exit(-1, "Second cmd");
	perror_and_exit(close(pipefd[1]), "close");
	perror_and_exit(dup2(pipefd[0], 0), "dup2");
	perror_and_exit(dup2(outfd, 1), "dup2");
	perror_and_exit(execve(path, newcmd, env), "execve");
	wait(NULL);
}
