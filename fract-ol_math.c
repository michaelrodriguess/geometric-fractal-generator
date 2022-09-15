/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:01:46 by microdri          #+#    #+#             */
/*   Updated: 2022/09/15 16:23:30 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

double	value_absolute(t_complex z)
{
	double result_value_absolute;

	result_value_absolute = sqrt(pow(z.r,2) + pow(z.i,2));

	return (result_value_absolute);
}

t_complex	complex_add(t_complex s_a, t_complex s_b)
{
	t_complex s;

	s.r = s_a.r + s_b.r;
	s.i	= s_a.i + s_b.i;

	return (s);
}

t_complex	complex_pow(t_complex p)
{
	t_complex result_p;
	
	result_p.r = (p.r * p.r) - (p.i * p.i);
	result_p.i = 2 * p.r * p.i;

	return(result_p);	
}

