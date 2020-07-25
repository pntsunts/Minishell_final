/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:18:41 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/24 13:37:16 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *s1, const char *s2, size_t dstsize)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (s1[x] && x < dstsize)
		x++;
	while ((s2[y] && (x + y + 1) < dstsize))
	{
		s1[x + y] = s2[y];
		y++;
	}
	if (x + y < dstsize)
		s1[x + y] = '\0';
	return (x + ft_strlen(s2));
}
