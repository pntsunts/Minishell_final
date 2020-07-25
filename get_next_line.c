/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 09:48:31 by pntsunts          #+#    #+#             */
/*   Updated: 2020/06/29 14:48:11 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_get_info(const int fd, char **line)
{
	char		*info;
	char		*temp;
	int			value;

	if ((info = (char *)malloc(sizeof(*info) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	value = read(fd, info, BUFF_SIZE);
	if (value > 0)
	{
		info[value] = '\0';
		temp = ft_strjoin(*line, info);
		free(*line);
		*line = temp;
	}
	free(info);
	return (value);
}

static int		read_and_join(const int fd, char **stack, char **lfeed)
{
	int			numchar;

	while (*lfeed == '\0')
	{
		numchar = ft_get_info(fd, *&stack);
		if (numchar == 0)
		{
			if (ft_strlen(*stack) == 0)
				return (0);
			*stack = ft_strjoin(*stack, "\n");
		}
		if (numchar < 0)
			return (-1);
		else
			*lfeed = ft_strchr(*stack, '\n');
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stack = NULL;
	char		*temp;
	int			ret;
	char		*lfeed;

	if ((!stack && (stack = (char*)malloc(sizeof(*stack))) == NULL) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	lfeed = ft_strchr(stack, '\n');
	ret = read_and_join(fd, &stack, &lfeed);
	if (ret == 0 || ret == -1)
	{
		if (ret == 0)
			*line = ft_strdup("");
		return (ret);
	}
	*line = ft_strsub(stack, 0, ft_strlen(stack) - ft_strlen(lfeed));
	temp = ft_strdup(lfeed + 1);
	ft_strdel(&stack);
	stack = temp;
	return (ret);
}
