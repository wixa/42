/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 22:00:35 by msarr             #+#    #+#             */
/*   Updated: 2013/12/15 22:00:39 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	ft_pp(t_lex **list2, t_lex *tmp)
{
	if (!*list2)
	{
		*list2 = tmp;
		(*list2)->prev = tmp;
		(*list2)->next = tmp;
	}
	else
	{
		tmp->prev = (*list2)->prev;
		(*list2)->prev->next = tmp;
		tmp->next = *list2;
		(*list2)->prev = tmp;
		*list2 = (*list2)->prev;
	}
}

void		ft_p(t_lex **list1, t_lex **list2, char c)
{
	t_lex	*tmp;

	if (*list1)
	{
		if (get_flag(*list1))
			write(1, " ", 1);
		tmp = *list1;
		tmp->name = c;
		if (*list1 == (*list1)->next)
			*list1 = NULL;
		else
		{
			*list1 = (*list1)->next;
			(*list1)->prev = tmp->prev;
			tmp->prev->next = *list1;
		}
		ft_pp(list2, tmp);
		write(1, "p", 1);
		write(1, &c, 1);
	}
}
