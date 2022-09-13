/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:01:46 by microdri          #+#    #+#             */
/*   Updated: 2022/09/13 20:01:48 by microdri         ###   ########.fr       */
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
//////////////////////////////////////////////////////////
/*int	get_iteration_mandelbrot(t_complex c)
{
	//Function for print if iterations is ok!
	t_complex	z;
	size_t		i;
	size_t		max_iteration;

	z.r = 0;
	z.i = 0;
	i = 0;
	max_iteration = 100;
	while (value_absolute(z) <= 2)
	{
		if (i == max_iteration)
			break ;
		z = complex_add(complex_pow(z), c);
		i++;
	}
	return (i);
}

int	get_iteration_julia(t_complex c, t_complex z, size_t max_iteration) 
{
	size_t	i;

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

void	fractol_julia(void *mlx_ptr, void *mlx_wd, double distance_of_pixel)
{
	t_complex c;
	t_complex z;
	int	window_x;
	int	window_y;

	window_x = 0;
	window_y = 0;
	c.r = -0.4 ;
	c.i = 0.6;
	z.r = -2;
	z.i = 2;
	while (z.i >= -2)
	{
		while (z.r <= 2)
		{
			if (get_iteration_julia(c, z, 50) == 50)
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

int main()
{
	//t_complex	c;
	double		distance_of_pixel;
	void		*mlx_ptr;
	void		*mlx_wd;
	int			window_x;
	int			window_y;

	window_x = 0;
	window_y = 0;
	mlx_ptr = mlx_init();
	mlx_wd = mlx_new_window(mlx_ptr, 1000, 1000, "Fract-ol");
	distance_of_pixel = (double) 4 / 1000;
//	c.r = -2;
//	c.i = 2;	
//	while(c.i >= -2)
//	{
//		while(c.r <= 2)
//		{
//			if (get_iteration(c) == 100)
//					mlx_pixel_put(mlx_ptr, mlx_wd, window_x, window_y, 0x0000FF);
//			else
//				mlx_pixel_put(mlx_ptr, mlx_wd, window_x, window_y, 0xFF0000);
//			c.r += distance_of_pixel;
//			window_x++;
//		}
//		window_x = 0;
//		window_y++;
//		c.r = -2;
//		c.i -= distance_of_pixel;
//		}
	fractol_julia(mlx_ptr, mlx_wd, distance_of_pixel);
	mlx_loop(mlx_ptr);
}*/
