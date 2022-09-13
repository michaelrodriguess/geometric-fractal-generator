/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:26:09 by microdri          #+#    #+#             */
/*   Updated: 2022/09/13 19:55:30 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	get_iteration_mandelbrot(t_complex c, int max_iteration)
{
	t_complex	z;
	int			i;

	z.r = 0;
	z.i = 0;
	i = 0;
	while (value_absolute(z) <= 2)
	{
		if (i == max_iteration)
			break ;
		z = complex_add(complex_pow(z), c);
		i++;
	}
	return (i);
}

int	get_iteration_julia(t_complex c, t_complex z, int max_iteration)
{
	int i;

	i = 0;
	while (value_absolute(z) <= 2)
	{
		if ( i == max_iteration)
			break ;
		z = complex_add(complex_pow(z), c);
		i++;
	}
	return (i);
}

void	fractol_mandelbrot(void *mlx_ptr, void *mlx_wd, int window_x, int window_y)
{
	t_complex c;
	double	distance_of_pixel;

	c.r = -2;
	c.i = 2;
	distance_of_pixel = (double) 4 / 1000;
	
	while (c.i >= -2)
	{
		while (c.r <= 2)
		{
			if (get_iteration_mandelbrot(c, 100) == 100)
				mlx_pixel_put(mlx_ptr, mlx_wd, window_x, window_y, 0x0000FF);
			else
				mlx_pixel_put(mlx_ptr, mlx_wd, window_x, window_y, 0xFF0000);
			c.r += distance_of_pixel;
			window_x++;
		}
		window_x = 0;
		window_y++;
		c.i -= distance_of_pixel;
	}
}

void	fractol_julia(void	*mlx_ptr, void *mlx_wd, int window_x, int window_y)
{
	t_complex	c;
	t_complex	z;
	double		distance_of_pixel;

	c.r = -0.79;
	c.i = 0.15;
	z.r = -2;
	z.i = 2;
	distance_of_pixel = (double) 4 / 1000;
	while (z.i <= -2)
	{
		while (z.r >= 2)
		{
			if (get_iteration_julia(c, z, 100) == 100)
				mlx_pixel_put(mlx_ptr, mlx_wd, window_x, window_y, 0x0000FF);
			else
				mlx_pixel_put(mlx_ptr, mlx_wd, window_x, window_y, 0xFF0000);
			z.r += distance_of_pixel;
			window_x++;
		}
		window_x = 0;
		window_y++;
		z.r = -2;
		z.i -= distance_of_pixel;
	}
}

