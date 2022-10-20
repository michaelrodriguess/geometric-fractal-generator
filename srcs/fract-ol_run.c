/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:31:25 by microdri          #+#    #+#             */
/*   Updated: 2022/10/14 19:09:00 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.x = 0;
	data.y = 0;
	data.zoom = 1.0;
	data.argv = argv;
	data.argc = argc;
	data.max_i = 2;
	data.max_r = 2;
	data.min_r = -2;
	data.min_i = -2;
	if (argc < 2 || argc == 3 || argc >= 5)
		set_error();
	verify_line_command(&data);
	data.mlx_ptr = mlx_init();
	data.mlx_wd = mlx_new_window(data.mlx_ptr, SIZE_DISPLAY,
			SIZE_DISPLAY, "Fract-ol");
	data.img = mlx_new_image(data.mlx_ptr, SIZE_DISPLAY, SIZE_DISPLAY);
	data.addr = mlx_get_data_addr(data.img,
			&data.bits_per_pixel, &data.line_length, &data.endian);
	select_fractol(&data);
	mlx_hook(data.mlx_wd, 17, 0, close_window, &data);
	mlx_key_hook(data.mlx_wd, key_hook, &data);
	mlx_mouse_hook(data.mlx_wd, mouse_func, &data);
	mlx_loop(data.mlx_ptr);
}
