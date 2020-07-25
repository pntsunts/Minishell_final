/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:43:20 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/14 12:47:40 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*x;

	x = (unsigned char*)s;
	while (len != 0)
	{
		*(x++) = (unsigned char)c;
		len--;
	}
	return (s);
}
