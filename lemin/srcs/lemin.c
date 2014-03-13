/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 15:52:26 by msarr             #+#    #+#             */
/*   Updated: 2014/03/13 14:16:15 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			epure(t_lemroom *room, t_lem *lem)
{
	int				i;

	i = tabroomlen(room->tab) - 1;
	while (room && room->tab && (room->tab)[i] && i)
	{
		(room->tab)[i] = NULL;
		i--;
	}
	if (room->tab && (room->tab)[0])
	{
		epure((room->tab)[0], lem);
		dellist(&(lem->tab[hashcode((room->tab[0])->name)]));
	}
}

void			epureall(t_lemroom *room, t_lem *lem)
{
	int				i;

	i = tabroomlen(room->tab) - 1;
	while (room && room->tab && (room->tab)[i] && i)
	{
		(room->tab)[i] = NULL;
		i--;
	}
	if (room->tab && (room->tab)[0])
		epure((room->tab)[0], lem);
}
