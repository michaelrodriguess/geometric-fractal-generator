/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:53:10 by microdri          #+#    #+#             */
/*   Updated: 2022/09/19 19:27:21 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# define MAX_ITERATION 100
# define SIZE_DISPLAY 1000

typedef struct n_window
{
	int x;
	int y;
}	t_window;

typedef struct n_complex
{
	double r;
	double i;
}	t_complex;

double		value_absolute(t_complex z);
t_complex	complex_add(t_complex s_a, t_complex s_b);
t_complex	complex_pow(t_complex p);
int			get_iteration_mandelbrot(t_complex c);
int			get_iteration_julia(t_complex c, t_complex z);
void		fractol_mandelbrot(void *mlx_ptr, void *mlx_wd, t_window window);
void		fractol_julia(void *mlx_ptr, void *mlx_wd, t_window window);
int			get_colors(int number_of_iterations);
int			check_number(int n);
int			hsv_to_hex(int h, int s, int v);

#endif
