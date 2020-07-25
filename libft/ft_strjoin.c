/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 10:59:33 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/25 13:02:15 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*st;

	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	st = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (st == NULL)
		return (NULL);
	while (s1[x] != '\0')
	{
		st[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		st[y + x] = s2[y];
		y++;
	}
	st[y + x] = '\0';
	return (st);
}
