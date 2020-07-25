/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:30:19 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/10 10:51:24 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*st;

	i = 0;
	if (!s || !(st = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		st[i] = s[start + i];
		i++;
	}
	st[i] = '\0';
	return (st);
}
