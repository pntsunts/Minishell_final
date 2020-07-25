/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pntsunts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 08:11:39 by pntsunts          #+#    #+#             */
/*   Updated: 2019/06/25 08:39:30 by pntsunts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_int_len(int n)
{
	int len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = ft_int_len(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	s[len] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		s[len - 1] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	return (s);
}
