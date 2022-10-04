/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:39:49 by microdri          #+#    #+#             */
/*   Updated: 2022/10/04 19:11:31 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	select_fractol(char **argv, t_data img)
{
	t_complex	c;

	if (ft_strnstr(argv[1], "mandelbrot", 10))
		fractol_mandelbrot(&img);
	else
	{
		c.r = ft_atof(argv[2]);
		c.i = ft_atof(argv[3]);
		fractol_julia(&img, c);
	}	
}

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_wd);
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *img)
{
	x = 0;
	y = 0;

	if (button == 4 )
	{
		ft_printf("zoom in\n");
		img->zoom += 0.5;
	}
	else if (button == 5)
	{
		ft_printf("zoom out\n");
		img->zoom -= 0.5;
	}
	mlx_clear_window(img->mlx_ptr, img->mlx_wd);
	fractol_mandelbrot(img);
	mlx_put_image_to_window(img->mlx_ptr, img->mlx_wd, img->img, 0, 0);

	return (0);
}

