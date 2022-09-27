/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:31:25 by microdri          #+#    #+#             */
/*   Updated: 2022/09/27 20:02:19 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		ret_bo;
	void	*mlx_ptr;
	void	*mlx_wd;
	t_window window;
	t_data img;
	
	ret_bo = 0;
	window.x = 0;
	window.y = 0;
	mlx_ptr = mlx_init();
	mlx_wd	= mlx_new_window(mlx_ptr, SIZE_DISPLAY, SIZE_DISPLAY, "Fract-ol");
	img.img = mlx_new_image(mlx_ptr, SIZE_DISPLAY, SIZE_DISPLAY);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	if (argc == 2)
	{
		ret_bo = verify_line_command(argv, &img, window);
		if (ret_bo != 1)
			message_error(argc, argv, &img, window);
			return (0);	
	}
	else 
		message_error(argc, argv, &img, window);
	mlx_put_image_to_window(mlx_ptr, mlx_wd, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
