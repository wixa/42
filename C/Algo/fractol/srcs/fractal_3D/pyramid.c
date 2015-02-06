/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 19:16:35 by msarr             #+#    #+#             */
/*   Updated: 2015/01/28 19:16:35 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*iterations=40000*/
t_coord		coord(double x, double y, double z)
{
	t_coord	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_coord		add(t_coord vect, t_coord vect1)
{
	t_coord	v;

	v.x = vect.x + vect1.x;
	v.y = vect.y + vect1.y;
	v.z = vect.z + vect1.z;
	return (v);
}

t_coord		mult(t_coord vect, double d)
{
	t_coord	v;

	v.x = vect.x * d;
	v.y = vect.y * d;
	v.z = vect.z * d;
	return (v);
}

void		plot3d(t_env *env, t_coord c, int i)
{
	double	x;
	double	y;

	x = (0.71 * (c.x - c.y) + 10) * 30.0;
	y = (-0.82 * c.z + 0.41 * (c.x + c.y) + 10) * 30.0;
	//printf("hhh %lf - %lf\n", x, y);
	if (x >= 0 && y >= 0)
	plotpixel(env, (int)x , (int)y, env->rgbmap[i % 3]);
}

void		pyramid(t_env *env, t_coord	p, int depth, double z, int j)
{
	t_coord	t[4];
	int 	i;

	if (depth)
	{
		t[0] = add(p, coord(-z / 2.0, -z / 2.0, -z));
		t[1] = add(p, coord(z / 2.0, -z / 2.0, -z));
		t[2] = add(p, coord(-z / 2.0, z / 2.0, -z));
		t[3] = add(p, coord(z / 2.0, z / 2.0, -z));
		i = -1;
		while (++i < 4)
		{
			plot3d(env, t[i], j);
			t[i] = mult(add(p, t[i]), 1.0 / 2.0);
		}
		expose(env);
		pyramid(env, t[0], depth -1, z / 2.0, 0);
		pyramid(env, t[1], depth -1, z / 2.0, 1);
		pyramid(env, t[2], depth -1, z / 2.0, 0);
		pyramid(env, t[3], depth -1, z / 2.0, 1);
		pyramid(env, p, depth -1, z / 2.0, j);
	}
}


int			main_attract(t_env *env)
{
	t_coord	t;

	t = coord(0.0, 0.0, 7.0);
	plot3d(env, t, 0);
	pyramid(env, t, 8, 7.0, 2);
	return (0);
}
