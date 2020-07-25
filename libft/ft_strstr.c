/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:27:57 by pntsunts          #+#    #+#             */
/*   Updated: 2019/05/30 07:46:02 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *s1, const char *s2)
{
	const char *x;
	const char *y;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		x = s1;
		y = s2;
		while (*y != '\0' && *x == *y)
		{
			x++;
			y++;
		}
		if (*y == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
