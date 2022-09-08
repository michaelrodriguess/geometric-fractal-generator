/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:53:10 by microdri          #+#    #+#             */
/*   Updated: 2022/09/08 18:55:37 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef struct n_complex
{
	double r;
	double i;
}	t_complex;

int			get_iteration(t_complex c);
double		value_absolute(t_complex z);
t_complex	complex_add(t_complex s_a, t_complex s_b);
t_complex	complex_pow(t_complex p);


#endif
