/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:31:25 by microdri          #+#    #+#             */
/*   Updated: 2022/09/26 20:04:06 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*mlx_wd;
	t_window window;
//	t_data img;

	window.x = 0;
	window.y = 0;
	mlx_ptr = mlx_init();
	mlx_wd	= mlx_new_window(mlx_ptr, SIZE_DISPLAY, SIZE_DISPLAY, "Fract-ol");
	//img.img = mlx_new_image(mlx_ptr, SIZE_DISPLAY, SIZE_DISPLAY);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	if (verify_line_command(argv, mlx_ptr, mlx_wd, window) == 0)
		ft_putstr_fd("Invalid Fractol Name, Try:\n", 2);

	if (argc == 2)
		verify_line_command(argv, mlx_ptr, mlx_wd, window);
	else
		message_error(argc);
	mlx_loop(mlx_ptr);
}
