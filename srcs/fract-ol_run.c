/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:31:25 by microdri          #+#    #+#             */
/*   Updated: 2022/10/04 18:41:33 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	main(int argc, char **argv)
{
	t_data 		data;
	
	data.x = 0;
	data.y = 0;
	data.zoom = 1.0;
	verify_line_command(argc, argv);
	data.mlx_ptr = mlx_init();
	data.mlx_wd	= mlx_new_window(data.mlx_ptr, SIZE_DISPLAY, SIZE_DISPLAY, "Fract-ol");
	data.img = mlx_new_image(data.mlx_ptr, SIZE_DISPLAY, SIZE_DISPLAY);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	select_fractol(argv, data);
	mlx_hook(data.mlx_wd, 17, 0, close_window, &data);
	mlx_key_hook(data.mlx_wd, key_hook, &data);
	mlx_mouse_hook(data.mlx_wd, mouse_hook, &data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_wd, data.img, 0, 0);
	mlx_loop(data.mlx_ptr);
}

