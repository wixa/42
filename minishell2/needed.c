/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:06:13 by msarr             #+#    #+#             */
/*   Updated: 2014/01/24 17:06:15 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell2.h"

void		print_err(char *cmd, char *text)
{
	ft_putstr_fd("ft_minishell2: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(text, 2);
}

char	**get_env(char	**env, char *str)
{
	char	*path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnequ(env[i], str, ft_strlen(str)) == 1)
			path = env[i];
		i++;
	}
	return (ft_strsplit(&path[ft_strlen(str) + 1], ':'));
}
