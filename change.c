/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:17:40 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/26 10:19:33 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd()
{
    char dir[1024];

    getcwd(dir, 1024);
    ft_putendl(dir);
}

void swipe(char *new_path)
{
	char old_path[1024];
	getcwd(old_path, 1024);

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
