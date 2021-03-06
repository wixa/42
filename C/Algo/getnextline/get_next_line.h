/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:42:23 by msarr             #+#    #+#             */
/*   Updated: 2013/12/02 17:42:27 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					GET_NEXT_LINE_H
# define				GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "./libft/includes/libft.h"

# define BUFF_SIZE 100

typedef struct			s_line
{
	int					fd;
	char				*str;
	struct s_line	*next;
}						t_line;

int						get_next_line(int const fd, char **line);

#endif
