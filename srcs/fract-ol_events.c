/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:31:06 by microdri          #+#    #+#             */
/*   Updated: 2022/10/14 18:58:27 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_wd);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	if (keycode == 123)
	{
		data->max_r -= 0.8;
		data->min_r -= 0.8;
	}
	else if (keycode == 124)
	{
		data->max_r += 0.8;
		data->min_r += 0.8;
	}
	else if (keycode == 125)
	{
		data->max_i -= 0.8;
		data->min_i -= 0.8;
	}
	else if (keycode == 126)
	{
		data->max_i += 0.8;
		data->min_i += 0.8;
	}
	select_fractol(data);
	return (0);
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
