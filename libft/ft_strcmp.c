/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:31:46 by pntsunts          #+#    #+#             */
/*   Updated: 2020/07/13 11:19:51 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	size_t x;

	x = 0;
	while ((unsigned char)s1[x] == (unsigned char)s2[x] && \
			((unsigned char)s1[x] != '\0') && ((unsigned char)s2[x] != '\0'))
		x++;
	if (((unsigned char)s1[x] - (unsigned char)s2[x]) > 0)
		return (1);
	else if (((unsigned char)s1[x] - (unsigned char)s2[x]) < 0)
		return (-1);
	else
		return (0);
}
