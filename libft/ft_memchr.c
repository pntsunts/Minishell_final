/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 08:57:56 by pntsunts          #+#    #+#             */
/*   Updated: 2019/05/29 09:10:32 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *x;

	x = (unsigned char*)s;
	while (n--)
	{
		if (*x == (unsigned char)c)
			return (x);
		x++;
	}
	return (NULL);
}
