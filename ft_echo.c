/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:38:48 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/27 16:37:35 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*Get_path(char *str)
{
	int i = 0;
	char *tmp;
	char *store;

	while (Data[i])
	{
		tmp = ft_strjoin(str, "=");
		if (compare(Data[i], tmp) == 1)
		{
			store = ft_strchr(Data[i], '=');
			ft_putstr(store + 1);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

int ft_echo(char **str)
{
	char *path;
	int i;
	int j;

	i = 1;
	if (!str[1])
	{
		write(1, "\n", 1);
		return (1);
	}
	while (str[i])
	{
		j = -1;

		while (str[i][++j] != '\0')
		{
			if (str[i][j] == '\"')
				str[i][j] = 127;
		}
		if (str[i][0] == '$')
		{
			path = Get_path(str[i++] + 1);
			continue ;
		}
		ft_putstr(str[i++]);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	return (1);
}
