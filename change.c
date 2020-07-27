/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:17:40 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/27 14:56:24 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*Get_cd(char *str)
{
	int i = 0;
	char *tmp;

	while (Data[i])
	{
		tmp = ft_strjoin(str, "=");
		if (compare(Data[i], tmp) == 1)
		{
			return (ft_strchr(Data[i], '=') + 1);
		}
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
    char old_path[1024];
	char store[1024];

    getcwd(old_path, 1024);
    if (chdir(new_path) < 0)
    {
        if (opendir(new_path) == NULL)
        {
            ft_putstr("minishell: cd: ");
            ft_putstr(new_path);
            ft_putendl(": No such file or directory");
        }
        else
            ft_putendl("error changing directory");
    }
    else
    {
		getcwd(store, 1024);
        setenv_cd("PWD", store);
        setenv_cd("OLDPWD", old_path);
    }
}


int set_cd(char **str)
{

	if (!str[0])
	{
		*str = Get_cd("HOME");
		swipe(*str);
	}
	else if (str[0][0] == '-' && !str[0][1])
	{
		swipe(Get_cd("OLDPWD"));
		return (1);
	}
	else if (str[0][0] == '~' && str[0][1] == '/' && str[0][2])
	{
		swipe(&str[0][2]);
		return (1);
	}
	else if (str[0][0] == '/' && str[0][1])
	{

		swipe(&str[0][1]);
		return (1);
	}
	else
	{
		ft_putendl("working");
		swipe(str[0]);
	}
	return (1);
}
