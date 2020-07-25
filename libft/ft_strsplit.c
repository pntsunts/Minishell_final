/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:15:58 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/15 10:44:38 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_c(char const *s, char c)
{
	unsigned int		i;
	int					cntw;

	i = 0;
	cntw = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntw++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntw);
}

static char			*ft_peter(char const *s, size_t n)
{
	char	*st;

	st = (char *)malloc(sizeof(char) * (n + 1));
	if (st == NULL)
		return (0);
	st = ft_strncpy(st, (char *)s, n);
	st[n] = '\0';
	return (st);
}

char				**ft_strsplit(char const *s, char c)
{
	int		x;
	int		y;
	int		z;
	char	**t;

	x = 0;
	y = 0;
	if (!s || (!(t = (char **)malloc(sizeof(char *) * (ft_c(s, c) + 1)))))
		return (NULL);
	while (s[x])
	{
		while (s[x] == c)
			x++;
		z = x;
		while ((s[x]) && (s[x] != c))
			x++;
		if (x > z)
		{
			t[y] = ft_peter(s + z, x - z);
			y++;
		}
	}
	t[y] = 0;
	return (t);
}
