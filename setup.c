/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 09:06:22 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/27 14:49:14 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	length(char *str)
{
	int x;
	char *tmp;
	x = 0;

	while (Data[x] != NULL)
	{
		tmp = ft_strjoin(str, "=");
		if (compare(Data[x], tmp) == 1)
		{
			free(tmp);
			return (x);
		}
		free(tmp);
		x++;
	}
	return (x);
}

static char **memory(int indexof)
{
	char **store;
	int i;

	i = -1;
	store = (char **)malloc(sizeof(char *) * (indexof + 1));

	while (Data[++i] && i < indexof)
	{
		store[i] = ft_strdup(Data[i]);
		free(Data[i]);
	}
	free(Data[i]);
	return (store);
}

void setenv_cd(char *str, char *some)
{
	int i;

	char *tmp;
	i = length(str);
	
	tmp = ft_strjoin("=", some);
	if (Data[i])
	{
		free(Data[i]);
		if (some)
			Data[i] = ft_strjoin(str, tmp);
	}
	else
	{
		Data = memory(i + 1);
		if (some)
			Data[i] = ft_strjoin(str, tmp);
		Data[i + 1] = NULL;
	}
	free(tmp);
}


