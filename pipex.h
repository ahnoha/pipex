/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:48:54 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/13 13:43:11 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

char	**ft_split(char const *s, char c);

char	*ft_getenv(char *env[], const char *var);
char	**get_paths(char *path);
char	*get_cmd(char *path, char *cmd);
char	*find_cmd_path(char *path, char *cmd);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *str);

void	perror_and_exit(int fd, const char *s);
void	ft_exec_child(char *av[], char *env[], int pipefd[2]);
void	ft_exec_parent(char *av[], char *env[], int pipefd[2]);
void	print_and_exit(const char *s);

#endif
