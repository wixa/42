/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 23:06:34 by msarr             #+#    #+#             */
/*   Updated: 2015/02/04 23:06:34 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct 		s_cplx
{
	double			r;
	double			i;
}					t_cplx;

double				mod(t_cplx a);
double		 		args(t_cplx c);
double				dot(t_cplx a, t_cplx b);
t_cplx				cplx_pow(t_cplx z, double n);
t_cplx				cplx(double r,double i);
t_cplx 				cplx_mult(t_cplx a, t_cplx b);
t_cplx 				cplx_mult2(t_cplx a, double b);
t_cplx				cplx_sqrt(t_cplx a);
t_cplx 				cplx_cos(t_cplx a);
t_cplx 				cplx_sub(t_cplx a, t_cplx b);
t_cplx 				cplx_add(t_cplx a, t_cplx b);
t_cplx				cplx_div(t_cplx lhs, t_cplx rhs);
t_cplx				formula(t_cplx z);
t_cplx				toangle(t_cplx z);

#endif
