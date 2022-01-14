/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:49:33 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/12 16:08:45 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getenv(char *env[], const char *var)
{
	int		i;
	size_t	len;

	len = ft_strlen(var);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0)
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

char	**get_paths(char *path)
{
	char	**paths;

	paths = ft_split(path, ':');
	return (paths);
}

char	*get_cmd(char *path, char *cmd)
{
	int		check;
	char	*full_path;
	char	*to_free;

	full_path = ft_strjoin(path, "/");
	if (!full_path)
		return (NULL);
	to_free = full_path;
	full_path = ft_strjoin(full_path, cmd);
	free(to_free);
	if (!full_path)
		return (NULL);
	check = access(full_path, X_OK);
	if (check == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*find_cmd_path(char *path, char *cmd)
{
	int		i;
	char	**paths;
	char	*full_path;

	i = 0;
	paths = get_paths(path);
	while (paths[i])
	{
		full_path = get_cmd(paths[i], cmd);
		if (full_path)
			return (full_path);
		i++;
	}
	return (NULL);
}
