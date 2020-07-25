/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:20:03 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/25 10:32:43 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] != '\0' && s1[x] == s2[x] && x < n - 1)
		x++;
	if (((unsigned char)s1[x] - (unsigned char)s2[x]) > 0)
		return (1);
	else if (((unsigned char)s1[x] - (unsigned char)s2[x]) < 0)
		return (-1);
	else
		return (0);
}
