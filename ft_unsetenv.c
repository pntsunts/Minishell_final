/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:20:55 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/26 13:40:06 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int compare(char *str1, char *str2)
{
	int i;

	i = -1;
	while (str2[++i])
	{
		if (str1[i] != str2[i])
		{
			return (0);
		}
	}
	return (1);

}

static size_t envLe(char **Data)
{
	int x;

	x = 0;
	while (Data[x] != NULL)
	{
		x++;
	}
	return (x);
}

void env_cop(char **env)
{
	int x;

	x = 0;
	while (Data[x] != NULL)
	{
		env[x] = Data[x];
		x++;
	}
	env[x] = NULL;
}

void env_unset(char *str)
{
	char *tmp;
	int i = 0;
	int j = 0;
	char **store;
	store = (char **)malloc(sizeof(char *) * (envLe(Data) + 1));
	env_cop(store);
	free(Data);
	Data = NULL;
	Data = (char **)malloc(sizeof(char *) * (envLe(store) + 1));

	while (store[i])
	{
		tmp = ft_strjoin(str, "=");
		if (compare(store[i], tmp) == 1)
		{
			i++;
		}
		Data[j] = store[i];
		j++;
		i++;
		free(tmp);
	}
	free(store);
	Data[j] = NULL;
}

int check(char **str)
{
	if (envLe(str) != 2)
	{
		ft_putendl("ft_unsetenv : \033[0mtoo few or many arguments\36m ");
		return (1);
	}
	env_unset(str[1]);
	return (0);
}
