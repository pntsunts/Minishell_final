/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 09:04:18 by pntsunts          #+#    #+#             */
/*   Updated: 2019/05/30 11:25:10 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t				i;
	unsigned char		*x;
	unsigned char		*y;

	x = (unsigned char*)s1;
	y = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		x[i] = y[i];
		if (x[i] == (unsigned char)c)
			return ((void*)(x + i + 1));
		++i;
	}
	return (NULL);
}
