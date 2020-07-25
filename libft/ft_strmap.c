/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:43:29 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/07 08:26:30 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(const char *s, char (*f)(char))
{
	unsigned int		i;
	char				*s1;

	i = 0;
	if (!(s) || !(s1 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		s1[i] = f(s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
