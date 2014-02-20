/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 12:29:08 by msarr             #+#    #+#             */
/*   Updated: 2013/11/24 12:29:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell2.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*cpy;

	i = ft_strlen(s1);
	cpy = (char*) malloc(sizeof(*s1) * (i + 1));
	cpy[i + 1] = '\0';
	while (i >= 0)
	{
		cpy[i] = s1[i];
		i--;
	}
	return (cpy);
}
