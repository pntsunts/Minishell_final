/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:07:59 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/25 09:12:28 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *x;
	unsigned char *y;

	x = (unsigned char*)dst;
	y = (unsigned char*)src;
	if (x == y)
		return (dst);
	if (y < x)
	{
		y = (unsigned char*)src + len - 1;
		x = dst + len - 1;
		while (len--)
			*x-- = *y--;
	}
	else
	{
		while (len--)
			*x++ = *y++;
	}
	return (dst);
}
