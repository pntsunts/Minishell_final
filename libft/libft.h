/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 09:34:25 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/27 07:16:05 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				ft_putchar(char c);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putendl(const char *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_putstr(char const *s);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putchar(char c);
void				ft_strdel(char **as);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_strncmp(const char*s1, const char*s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *s1, const char *s2);
size_t				ft_strlcat(char *s1, const char *s2, size_t dstsize);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strdup(char *s1);
char				*ft_itoa(int n);
char				*ft_strchr(const char *s, int c);
char				*ft_strnstr(const char *str, const char *to_find, int n);
#endif
