/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:26:09 by microdri          #+#    #+#             */
/*   Updated: 2022/09/15 17:04:59 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	get_iteration_mandelbrot(t_complex c)
{
	t_complex	z;
	int			i;

	z.r = 0;
	z.i = 0;
	i = 0;
	while (value_absolute(z) <= 2)
	{
		if (i == MAX_ITERATION)
			break ;
		z = complex_add(complex_pow(z), c);
		i++;
	}
	return (i);
}

int	get_iteration_julia(t_complex c, t_complex z)
{
	int i;

	i = 0;
	while (value_absolute(z) <= 2)
	{
		if ( i == MAX_ITERATION)
			break ;
		z = complex_add(complex_pow(z), c);
		i++;
	}
	return (i);
}

void	fractol_mandelbrot(void *mlx_ptr, void *mlx_wd, t_window window)
{
	t_complex	c;
	double		distance_of_pixel;

	c.r = -2;
	c.i = 2;
	distance_of_pixel = (double) 4 / SIZE_DISPLAY;
	while (c.i >= -2)
	{
		while (c.r <= 2)
		{
			if (get_iteration_mandelbrot(c) == 100)
				mlx_pixel_put(mlx_ptr, mlx_wd, window.x, window.y, 0xFF0000);
			else
				mlx_pixel_put(mlx_ptr, mlx_wd, window.x, window.y, 0x00FF00);
			c.r += distance_of_pixel;
			window.x++;
		}
		window.x = 0;
		window.y++;
		c.r = -2;
		c.i -= distance_of_pixel;
	}
}

void	fractol_julia(void	*mlx_ptr, void *mlx_wd, t_window window)
{
	t_complex	c;
	t_complex	z;
	double		distance_of_pixel;

	c.r = -0.79;
	c.i = 0.15;
	z.r = -2;
	z.i = 2;
	distance_of_pixel = (double) 4 / SIZE_DISPLAY;
	while (z.i >= -2)
	{
		while (z.r <= 2)
		{
			if (get_iteration_julia(c, z) == 100)
				mlx_pixel_put(mlx_ptr, mlx_wd, window.x, window.y, 0xFF0000);
			else
				mlx_pixel_put(mlx_ptr, mlx_wd, window.x, window.y, 0x00FF00);
			z.r += distance_of_pixel;
			window.x++;
		}
		window.x = 0;
		window.y++;
		z.r = -2;
		z.i -= distance_of_pixel;
	}
}

