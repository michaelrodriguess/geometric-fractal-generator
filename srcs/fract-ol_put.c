/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:39:49 by microdri          #+#    #+#             */
/*   Updated: 2022/09/26 20:02:44 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <string.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int verify_line_command(char **argv, void *mlx_ptr, void *mlx_wd, t_window window)
{
		
	if (strnstr(argv[1], "mandelbrot", 10))
		fractol_mandelbrot(mlx_ptr, mlx_wd,window);
	else if (strnstr(argv[1], "julia", 5))
		fractol_julia(mlx_ptr, mlx_wd, window);
	else 
		return (0);

	return (1);
}