/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/12/25 21:16:07 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <errno.h>
# include <stdio.h>
# include "libft.h"
# include "struct.h"

/*
** Functions
*/

t_lem				*parse();
t_lex				*get_lst();
t_lem				*newlem(void);
void				send(t_room *r, t_lem *lem);
int 				is_num(char *str);
t_room				*new_room(char *str, int x, int y);
int					sort(t_room **r);
t_link				*sort_link(t_link *l);
int					hash(char *str);
t_lex				*get_door(t_lem *lem, t_lex *l, int flag);
t_link				*new_link(t_room *room);
t_link				*link_lst(t_link *l, t_room *room);
int					way(t_room *room, t_lem *lem);
t_lex				*add_link(t_lem *lem, t_lex *l);
int					hash(char *str);
int					lemin(t_lem *lem);
void				del_lem(t_lem **lem);


#endif