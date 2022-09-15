/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:31:25 by microdri          #+#    #+#             */
/*   Updated: 2022/09/15 17:05:25 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <string.h>

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*mlx_wd;
	t_window window;


	window.x = 0;
	window.y = 0;
	mlx_ptr = mlx_init();
	mlx_wd = mlx_new_window(mlx_ptr, SIZE_DISPLAY, SIZE_DISPLAY, "Fract-ol");
	if (argc == 2)
	{
		if (strnstr(argv[1], "Mandelbrot", 10))
		{
			fractol_mandelbrot(mlx_ptr, mlx_wd, window);
			puts("1");
		}
		if (strnstr(argv[1], "Julia", 5))
		{
			fractol_julia(mlx_ptr, mlx_wd, window);
			puts("2");
		}
	}
	else
		write(1, "Ta errado ai os argumento mermaoooooooooo\n", 42);
	mlx_loop(mlx_ptr);
}
