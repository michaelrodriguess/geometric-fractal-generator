/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:26:09 by microdri          #+#    #+#             */
/*   Updated: 2022/10/14 18:59:07 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_mandel(t_complex c)
{
	t_complex	temp;
	t_complex	z;
	int			i;

	z.r = 0;
	z.i = 0;
	i = 0;
	while ((z.i * z.i) + (z.r * z.r) <= 4)
	{
		if (i == MAX_ITERATION)
			break ;
		temp.r = (z.r * z.r) - (z.i * z.i);
		temp.i = 2 * z.r * z.i;
		z = temp;
		z.i = z.i + c.i;
		z.r = z.r + c.r;
		i++;
	}
	return (i);
}

int	iter_julia(t_complex c, t_complex z)
{
	t_complex	temp;
	int			i;

	i = 0;
	while ((z.i * z.i) + (z.r * z.r) <= 4)
	{
		if (i == MAX_ITERATION)
			break ;
		temp.r = (z.r * z.r) - (z.i * z.i);
		temp.i = 2 * z.r * z.i;
		z = temp;
		z.i = z.i + c.i;
		z.r = z.r + c.r;
		i++;
	}
	return (i);
}

void	fractol_mandelbrot(t_data *data)
{
	t_complex	c;

	c.i = data->max_i * data->zoom;
	c.r = data->min_r * data->zoom;
	mlx_clear_window(data->mlx_ptr, data->mlx_wd);
	data->distance_of_pixel = (double)(4 * data->zoom) / SIZE_DISPLAY;
	while (c.i >= data->min_i * data->zoom && data->y < SIZE_DISPLAY)
	{
		while (c.r <= data->max_r * data->zoom && data->x < SIZE_DISPLAY)
		{
			if (iter_mandel(c) == MAX_ITERATION)
				my_pixel_put(data, data->x, data->y, 0x000000);
			else
				my_pixel_put(data, data->x, data->y, colors(iter_mandel(c)));
			c.r += data->distance_of_pixel;
			data->x++;
		}
		data->x = 0;
		data->y++;
		c.r = data->min_r * data->zoom;
		c.i -= data->distance_of_pixel;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_wd, data->img, 0, 0);
	data->x = 0;
	data->y = 0;
}

void	fractol_julia(t_data *data, t_complex c)
{
	t_complex	z;

	z.r = -data->min_r * data->zoom;
	z.i = data->max_i * data->zoom;
	mlx_clear_window(data->mlx_ptr, data->mlx_wd);
	data->distance_of_pixel = (double)(4 * data->zoom) / SIZE_DISPLAY;
	while (z.i >= data->min_i * data->zoom && data->y < SIZE_DISPLAY)
	{
		while (z.r <= data->max_r * data->zoom && data->x < SIZE_DISPLAY)
		{
			if (iter_julia(c, z) == MAX_ITERATION)
				my_pixel_put(data, data->x, data->y, 0x000000);
			else
				my_pixel_put(data, data->x, data->y, colors(iter_julia(c, z)));
			z.r += data->distance_of_pixel;
			data->x++;
		}
		data->x = 0;
		data->y++;
		z.r = data->min_r * data->zoom;
		z.i -= data->distance_of_pixel;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_wd, data->img, 0, 0);
	data->x = 0;
	data->y = 0;
}
