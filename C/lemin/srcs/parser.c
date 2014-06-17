/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/06/17 01:24:18 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int			is_comment(char *str)
{
	if (str && str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

static t_getline	*addlist(t_getline *list, char *str)
{
	t_getline	*tmp;
	t_getline	*tmp1;

	tmp = (t_getline *)malloc(sizeof(t_getline));
	tmp->str = ft_strdup(str);
	if (!list)
		return (tmp);
	else
	{
		tmp1 = list;
		while (tmp1 && tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = tmp;
		return (list);
	}
}

static t_getline	*lexor()
{
	char			*str;
	t_getline		*list;

	str = NULL;
	list = NULL;
	while (get_next_line(0, &str))
	{
		ft_putendl(str);
		if (is_comment(str))
			continue ;
		else if (str && (*str == 'L' || *str == '\0'))
			return (list);
		else if (str)
			list = addlist(list, str);
		ft_memdel((void **)&str);
	}
	return (list);
}

t_lem				*parse()
{
	t_lem			*pars;
	t_getline		*list;

	list = NULL;
	if ((list = lexor()))
	{
		pars = newlem();
		if (!(pars->j = ft_atoi(list->str)))
			return (pars);
		list = list->next;
		if (!(get_start_end(list, pars)))
			return (pars);
		while ((list = list->next))
		{
			if (ft_is(list->str, ' '))
				get_room(list->str, pars);
			else if (ft_is(list->str, '-'))
				get_tab(list->str, pars);
			else
				return (pars);
		}
		return (pars);
	}
	return (NULL);
}
