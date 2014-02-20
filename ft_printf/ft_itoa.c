/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:03:59 by msarr             #+#    #+#             */
/*   Updated: 2013/11/21 15:04:13 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(int n)
{
	size_t		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*str;
	char		c;
	int			i;
	size_t		len;

	i = 0;
	len = ft_intlen(n);
	str = ft_strnew(len + 1);
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
		str[len - 1] = '-';
	while (n)
	{
		if (n < 0)
			c = (n % 10) * -1 + '0';
		else
			c = n % 10 + '0';
		n = n / 10;
			str[i] = c;
			i++;
	}
	str = ft_strreverse(str);
	str[len] = '\0';
	return (str);
}
