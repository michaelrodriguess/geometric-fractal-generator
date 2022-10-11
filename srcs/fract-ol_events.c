/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:31:06 by microdri          #+#    #+#             */
/*   Updated: 2022/10/11 19:31:20 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_wd);
	exit(0);
	return(0);
}

int key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	if (keycode == 123) //andar pra esquerda
	{
		data->max_r -= 0.5;
		data->min_r -= 0.5;
		select_fractol(data);
	}
	if (keycode == 124) //andar pra direita
	{
		data->max_r += 0.5;
		data->min_r += 0.5;
		select_fractol(data);
	}
	if (keycode == 125) //andar para baixo
	{
		data->max_i -= 0.5;
		data->min_i -= 0.5;
		select_fractol(data);
	}
	if (keycode == 126) //andar para cima
	{
		data->max_i += 0.5;
		data->min_i += 0.5;
		select_fractol(data);
	}	
	return(0);
}

int	mouse_func(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		data->zoom *= 1.1;
		select_fractol(data);
	}
	if (button == 5)
	{
		data->zoom *= 0.9;
		select_fractol(data);
	}
	return (0);
}
