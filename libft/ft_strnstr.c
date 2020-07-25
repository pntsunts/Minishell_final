/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:28:31 by pntsunts          #+#    #+#             */
/*   Updated: 2019/05/30 08:14:03 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *str, const char *to_find, int n)
{
	const char	*x;
	const char	*y;
	int			i;

	if (*to_find == '\0')
		return ((char*)str);
	while (*str != '\0' && n > 0)
	{
		x = str;
		y = to_find;
		i = n;
		while (*y != '\0' && *x == *y && i--)
		{
			x++;
			y++;
		}
		if (*y == '\0')
			return ((char*)str);
		str++;
		--n;
	}
	return (NULL);
}
