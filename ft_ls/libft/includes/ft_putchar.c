/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:03:05 by msarr             #+#    #+#             */
/*   Updated: 2013/11/21 15:03:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
 
void	ft_putchar(char c)
{
	write(1 ,&c ,1);
}
