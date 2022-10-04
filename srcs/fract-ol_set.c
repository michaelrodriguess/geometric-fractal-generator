/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:26:09 by microdri          #+#    #+#             */
/*   Updated: 2022/10/04 19:10:51 by microdri         ###   ########.fr       */
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

void	fractol_mandelbrot(t_data *img)
{
	t_complex	c;
	double		distance_of_pixel;

	c.i = 2 * img->zoom;
	c.r = -2 * img->zoom;
	distance_of_pixel = (double) (4 * img->zoom) / SIZE_DISPLAY; 
	while (c.i >= -2 * img->zoom && img->y < SIZE_DISPLAY)
	{
		while (c.r <= 2 * img->zoom && img->x < SIZE_DISPLAY)
		{
			if (get_iteration_mandelbrot(c) == MAX_ITERATION)
				my_mlx_pixel_put(img, img->x, img->y, 0x000000);
			else
				my_mlx_pixel_put(img, img->x, img->y, get_colors(get_iteration_mandelbrot(c)));
			c.r += distance_of_pixel;
			img->x++;
		}
		img->x = 0;
		img->y++;
		c.r = -2 * img->zoom;
		c.i -= distance_of_pixel;
	}
}

void	fractol_julia(t_data *img, t_complex c)
{
	t_complex	z;
	double		distance_of_pixel;

	z.r = -2;
	z.i = 2;
	distance_of_pixel = (double) 4 / SIZE_DISPLAY;
	while (z.i >= -2 && img->y < SIZE_DISPLAY)
	{
		while (z.r <= 2 && img->x < SIZE_DISPLAY)
		{
			if (get_iteration_julia(c, z) == MAX_ITERATION)
				my_mlx_pixel_put(img, img->x, img->y, 0x00000);
			else
				my_mlx_pixel_put(img, img->x, img->y, get_colors(get_iteration_julia(c, z)));
			z.r += distance_of_pixel;
			img->x++;
		}
		img->x = 0;
		img->y++;
		z.r = -2;
		z.i -= distance_of_pixel;
	}
}

