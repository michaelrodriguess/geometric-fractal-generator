/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:39:49 by microdri          #+#    #+#             */
/*   Updated: 2022/10/13 20:36:17 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	select_fractol(t_data *data)
{
	t_complex	c;

	if (ft_strnstr(data->argv[1], "mandelbrot", 10) && data->argc == 2)
		fractol_mandelbrot(data);
	else if (ft_strnstr(data->argv[1], "julia", 5) && data->argc == 4)
	{
		verify_arguments(data->argv[2]);
		verify_arguments(data->argv[3]);
		c.r = ft_atof(data->argv[2]);
		c.i = ft_atof(data->argv[3]);
		fractol_julia(data, c);
	}
	else
		set_error();
}
