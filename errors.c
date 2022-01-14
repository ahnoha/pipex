/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerraou <nerraou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:16:58 by nerraou           #+#    #+#             */
/*   Updated: 2022/01/13 13:44:10 by nerraou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_and_exit(int ret, const char *s)
{
	if (ret == -1)
	{
		perror(s);
		exit(EXIT_FAILURE);
	}
}

void	print_and_exit(const char *s)
{
	write(2, s, ft_strlen(s));
	exit(EXIT_FAILURE);
}
