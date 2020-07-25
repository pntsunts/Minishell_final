/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:06:22 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/25 08:44:39 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	unsigned int	i;
	int				x;
	int				y;

	y = 1;
	i = 0;
	x = 0;
	if (ft_strlen(str) >= 19 && ft_strcmp("9223372036854775807", str) < 0)
		return (-1);
	if (ft_strlen(str) >= 20 && ft_strcmp("-9223372036854775807", str) < 0)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			y = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10 + str[i] - '0';
		i++;
	}
	return ((int)(x * y));
}
