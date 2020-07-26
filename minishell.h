/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:05:26 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/26 08:54:56 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>

#define	BUFF_SIZE 32

char **Data;

void set_envp(char *str, char *value);
int		get_next_line(const int fd, char **line);
size_t  dataLen(char **str);
int checkStr(char **str);
int check(char **str);
int ft_echo(char **str);
char *Get_path(char *str);
int compare(char *str1, char *str2);
int error(char **str);
int count(char *str);
char **split(char *str);
void cd(char *new_path);
void pwd();
void env_setup(char *str, char *envval);
int set_cd(char **str);
char *Get_cd(char *str);
int exe(char **str);
int bin(char **str);
int in_exec(char *str, char **arg);
void swipe(char *new_path);
int free_str(char **str);
//void Path_unset(char *str);

#endif
