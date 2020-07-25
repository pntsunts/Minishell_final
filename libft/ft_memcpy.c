/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:28:29 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/05 14:00:09 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*y;
	char		*x;
	size_t		i;

	i = 0;
	x = (char*)s1;
	y = (char*)s2;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	while (i < n)
	{
		x[i] = y[i];
		i++;
	}
	return (s1);
}
