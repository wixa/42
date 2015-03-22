/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 15:03:34 by msarr             #+#    #+#             */
/*   Updated: 2015/01/20 15:03:34 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		getarg(void *arg, t_env **env, int *x, int *y)
{
	*env = ((t_thread *)arg)->env;
	*x = -1;//((t_thread *)arg)->x;
	*y = ((t_thread *)arg)->y;
}

void		*mandel(void *arg)
{
	t_env	*env;
	int		x;
	int		y;
	int		i;
	t_cplx	 z;
	t_cplx	 a;
	t_cplx	 c;

	getarg(arg, &env, &x, &y);
	while (++x < SCREEN_W)
	{
		c.r = (double)x / env->zoom_x + env->x_min;
		c.i = env->y_max - (double)y / env->zoom_y;
		z = cplx(0.0, 0.0);
		a = cplx(c.r, c.i);
		i = -1;
		while (mod(z) < 16 && ++i < env->max_i)
		{
			z = cplx_add(cplx_mult(z, z), c);
			a = heart(env->coeff[i % env->nc], a.r, a.i);
		}
		if (i == env->max_i)
			plotpixel(env, x, y, Black);
		else
			plotpixel(env, x, y, getcolor(a));
	}
	return (NULL);
}
