/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 11:09:59 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/27 13:21:43 by pntsunts         ###   ########.fr       */
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
	else 
	{
		if (pid > 0)
			wait(&pid);
			if (ft_strcmp(str, "exit") == 0)
				exit(0);
	}
	return (1);
}

int bin(char **str)
{
	struct stat filestat;

	if (access(str[0], F_OK) != 0)
	{
		ft_putstr("command not found :");
		ft_putendl(str[0]);
	}
	else
	{
		if (lstat(str[0], &filestat) != -1)
		{
			if (filestat.st_mode & S_IXUSR)
			{
				in_exec(str[0], str);
				return (1);
			}
		}
	}
	return (1);
}
