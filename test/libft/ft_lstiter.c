/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraccah <sraccah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 19:00:25 by sraccah           #+#    #+#             */
/*   Updated: 2015/03/25 18:52:50 by sraccah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	if (lst && lst->next && lst->next->next && f)
	{
		f(lst);
		f(lst->next);
		f(lst->next->next);
	}
	else if (lst && lst->next && f)
	{
		f(lst);
		f(lst->next);
	}
	else if (lst && f)
		f(lst);
}
