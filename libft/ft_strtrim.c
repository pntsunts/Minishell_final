/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:15:30 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/11 08:45:49 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	unsigned int		x;
	unsigned int		y;
	unsigned int		z;
	char				*st;

	x = 0;
	z = 0;
	if (!s)
		return (NULL);
	while (s[x] == ' ' || s[x] == '\n' || s[x] == '\t')
		x++;
	if (s[x] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	y = ft_strlen(s) - 1;
	while (s[y] == ' ' || s[y] == '\n' || s[y] == '\t')
		y--;
	if (!(st = (char *)malloc(sizeof(char) * (y - x + 2))))
		return (NULL);
	while (z < y - x + 1)
	{
		st[z] = s[x + z];
		z++;
	}
	st[z] = '\0';
	return (st);
}
