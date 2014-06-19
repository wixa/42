/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozzie <mozzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 19:56:12 by msarr             #+#    #+#             */
/*   Updated: 2014/06/18 11:08:27 by mozzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LEMIN_H
# define	LEMIN_H

# include <errno.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"

/*
** Lists and Strutures
*/

typedef struct 			s_lemroom
{
	int					dist;
	int					step;
	int					lem;
	char				*name;
	struct s_lemroom	**tab;
}						t_lemroom;

typedef struct 			s_lem
{
	t_lemroom			*tab[1000];
	int					j;
	char				*start;
	t_lemroom			*lem_start;
	t_lemroom			*lem_end;
	char				*end;
}						t_lem;

/*
** Functions
*/

t_lem					*parse();
t_lem					*newlem(void);
void					lemin(t_lem *lem);
void					dellem(t_lem **lem);
t_lemroom				**newtabroom(int i);
t_lemroom				**alloctabroom(int i);
t_lemroom				*newendroom(char *str);
void					delroom(t_lemroom **room);
void					sort(t_lemroom **tabroom);
void					moove(t_lemroom **tab, int k);
void					deltabroom(t_lemroom ***room);
int						tabroomlen(t_lemroom **tabroom);
t_lemroom				*allocroom(char *str);
void					weight(t_lemroom *room, t_lem *lem);
void					connect(t_lemroom *room, t_lem *lem);
int						get_room(char *str, t_lem *pars, int flag);
int						get_tab(char *str, t_lem *pars);
int						get_start_end(t_getline *list, t_lem *pars);
t_lemroom				**allconnect(t_lemroom **room, t_lem *lem);
void					addroom(t_lemroom *room, char *str);
t_lemroom				**recupnextroom(t_lemroom **tabroom, t_lem *lem);
void					putroom(t_lemroom *room, t_lemroom *room1, int j);
void					putroomb(t_lemroom *room);
t_lemroom				**merge(t_lemroom ***tabroom, t_lemroom **tabroom1);

#endif/* !LEMIN_H */