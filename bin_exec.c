/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 11:09:59 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/26 11:16:18 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int in_exec(char *str, char **arg)
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		execve(&str[0], arg, Data);
	}
	wait(&pid);
	return (1);
}

int bin(char **str)
{
	if (access(str[0], F_OK) != 0)
	{
		ft_putstr("command not found :");
		ft_putendl(str[0]);
	}
	in_exec(str[0], str);
	return (1);
}
