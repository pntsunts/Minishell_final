/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:17:40 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/26 11:22:47 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*Get_cd(char *str)
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
			return (store + 1);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

void pwd()
{
    char dir[4096];

    getcwd(dir, 4096);
	ft_putendl(dir);
}

void swipe(char *new_path)
{
	char old_path[4096];
	getcwd(old_path, 4096);

	if (chdir(new_path) < 0)
	{
		if (opendir(new_path) == NULL)
		{
			ft_putstr("minishell: cd: ");
			ft_putstr(new_path);
			ft_putendl(" : No such file or directory");
		}
		else
			ft_putendl("error changing directory");
	}
	else
	{
		env_setup("PWD", new_path);
		env_setup("OLDPWD", old_path);
	}
}

int set_cd(char **str)
{
	char *path;

	path = Get_cd("HOME");

	if (!str[1] || (str[1][0] == '~' && !str[1][1]))
	{
		swipe(path);
		return (1);
	}
	else if (str[1][0] == '-' && !str[1][1])
	{
		swipe(Get_cd("OLDPWD"));
		return (1);
	}
	if (str[1][0] == '~' && str[1][1] == '/' && str[1][2])
	{
		swipe(&str[1][2]);
		return (1);
	}
	else if (str[1][0] == '/' && str[1][1])
	{
		swipe(&str[1][1]);
		return (1);
	}
	swipe(str[1]);
	return (1);
}
