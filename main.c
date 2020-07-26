/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 10:59:37 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/26 13:43:37 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	dataLen(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	return (i);
}

static char *getLines()
{
	char *line;
	line = NULL;
	get_next_line(0, &line);
	return (line);
}

static void printData()
{
	int i;

	i = 0;
	while (Data[i])
	{
		ft_putendl(Data[i]);
		i++;
	}
}

static int check_args(char **str)
{
	int run;

	run = 1;

	if (!str || !*str || !**str || str[0] == NULL)
	{
		return (1);
	}
	else if (ft_strcmp(*str, "exit") == 0)
	{
		return (0);
	}
	else if (ft_strcmp(*str, "env") == 0)
	{
		printData();
		return (1);
	}
	else if (ft_strcmp(str[0], "cd") == 0)
	{
		set_cd(str);
		return (1);
	}
	else if (ft_strcmp(*str, "setenv") == 0)
	{
		checkStr(str);
		return (1);
	}
	else if (ft_strcmp(*str, "echo") == 0)
	{
		ft_echo(str);
		return (1);
	}
	else if (ft_strcmp(*str, "unsetenv") == 0)
	{
		check(str);
		return (1);
	}
	else if (ft_strcmp(*str, "pwd") == 0)
	{
		pwd();
		return (1);
	}
	return (bin(str));
}

static void	readFiles(void)
{
	char	*str;
	char	**arg;
	int		run;
	int		i = 0;

	run = 1;
	while (run)
	{
		ft_putstr("Wethinkcode\033[32m$>\033[36m ");
		str = getLines();
		arg = split(str);
		run = check_args(arg);
		free(str);
	}
	free(arg[i++]);
}

static char  **getData(char **str)
{
	int i;

	i = 0;

	Data = (char **)malloc(sizeof(char *) * (dataLen(str) + 1));

	while (str[i])
	{
		(Data[i] = ft_strdup(str[i]));
		i++;
	}
	Data[i] = NULL;
	return (Data);
}

int free_str(char **str)
{
	int i = 0;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int main(int ac, char **av, char **str)
{
	int i = 0;
	(void)ac;
	(void)av;
	getData(str);
	readFiles();
	free(Data[i++]);
	return (0);
}
