/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:31:25 by microdri          #+#    #+#             */
/*   Updated: 2022/09/13 20:18:55 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <string.h>

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*mlx_wd;
	int		window_x;
	int		window_y;

	window_x = 0;
	window_y = 0;
	mlx_ptr = mlx_init();
	mlx_wd = mlx_new_window(mlx_ptr, 1000, 1000, "Fract-ol");
	if (argc == 2)
	{
		if (strcmp(argv[1], "Mandelbrot"))
			fractol_mandelbrot(mlx_ptr, mlx_wd, window_x, window_y);
		if (strcmp(argv[1], "Julia"))
			fractol_julia(mlx_ptr, mlx_wd, window_x, window_y);
	}
	else
		write(1, "Ta errado ai os argumento mermaoooooooooo\n", 42);
	mlx_loop(mlx_ptr);
}
