/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 09:03:53 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/27 13:47:45 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	envLen(char **Data)
{
	int x;

	x = 0;
	while (Data[x] != NULL)
	{
		x++;
	}
	return (x);
}

/*void env_copy(char **env)
{
	int x;

	x = 0;
	while(Data[x] != NULL)
	{
		env[x] = Data[x];
		x++;
	}
	env[x] = NULL;
}

void env_setup(char *str, char *envval)
{
	char *tmp;
	char **store;


	store = (char **)malloc(sizeof(char *) * (envLen(Data) + 1));
	env_copy(store);
	free(Data);
	Data = NULL;
	Data = store;
	tmp = ft_strjoin(str, ft_strjoin("=", envval));
	Data[envLen(Data) + 1] = NULL;
	Data[envLen(Data)] = tmp;
}*/

int checkStr(char **str)
{
	if (envLen(str) != 3)
	{
		ft_putendl("setenv : \033[0mtoo few or many arguments\36m ");
		return (1);
	}
	//env_setup(str[1], str[2]);
	setenv_cd(str[1], str[2]);
	return (0);
}
