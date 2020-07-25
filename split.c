/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 11:14:11 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/25 12:21:57 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int count(char *str)
{
	unsigned int i = 0;

	int len = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] != '\0')
			len++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (len);
}

char	**split(char *str)
{
	int i = 0;
	int x = 0;
	int y = 0;
	char **res;

	if (!(res = (char **)malloc(sizeof(char *) * (count(str) + 1))))
		return (NULL);
	while (str[i])
	{
		y = 0;
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		if (!(res[x] = (char *)malloc(sizeof(char) * (count(str) + 1))))
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			res[x][y] = str[i];
			i++;
			y++;
		}
		res[x][y] = '\0';
		x++;
	}
	res[x] = NULL;
	return (res);
}
