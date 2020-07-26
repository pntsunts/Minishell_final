/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:33:19 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/26 13:29:59 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	envLen(char *str)
{
	int x;

	x = 0;
	(void)str;
	while (Data[x])
	{
		x++;
	}
	return (x);
}

static size_t Len(char **Data)
{
	int x;

	x = 0;
	while (Data[x] != NULL)
	{
		x++;
	}
	return (x);
}

static char **memory(int indexof)
{
	int i;
	char **store;

	i = -1;

	store = (char **)malloc(sizeof(char *) * (indexof + 1));

	while (Data[++i] && i < indexof)
	{
		store[i] = ft_strdup(Data[i]);
	}
	return (store);
}

void	env_setup(char *str, char *envval)
{
	char *tmp;
	int i;

	i = envLen(str);
	tmp = ft_strjoin("=", envval);
	if (Data[i])
	{
		free(Data[i]);
		if (envval)
			Data[i] = ft_strjoin(str, tmp);
	}
	else
	{
		Data = memory(i + 1);
		if (envval)
		{
			Data[i] = ft_strjoin(str, tmp);
		}
		Data[i + 1] = NULL;
	}
	free(tmp);
}

int checkStr(char **str)
{
	if (Len(str) != 3)
	{
		ft_putendl("setenv : \033[0mtoo few or many arguments\36m ");
		return (1);
	}
	env_setup(str[1], str[2]);
	return (0);
}

