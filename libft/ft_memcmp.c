/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:46:24 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/05 09:10:40 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*x;
	char	*y;
	size_t	i;

	x = (char *)s1;
	y = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (x[i] != y[i])
			return ((unsigned char)x[i] - (unsigned char)y[i]);
		i++;
	}
	return (0);
}
