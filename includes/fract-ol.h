/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:53:10 by microdri          #+#    #+#             */
/*   Updated: 2022/10/13 19:51:17 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# define MAX_ITERATION 100
# define SIZE_DISPLAY 800

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_wd;
	void	*img;
	char	*addr;
	char	**argv;
	int		argc;
	int		x;
	int		y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	distance_of_pixel;
	double	zoom;
	double	max_i;
	double	min_i;
	double	max_r;
	double	min_r;
}				t_data;

typedef struct s_complex
{
	double r;
	double i;
}	t_complex;

int			get_iteration_mandelbrot(t_complex c);
int			get_iteration_julia(t_complex c, t_complex z);
void		fractol_mandelbrot(t_data *data);
void		fractol_julia(t_data *data, t_complex c);
int			get_colors(int number_of_iterations);
int			check_number(int n);
int			hsv_to_hex(int h, int s, int v);
int			key_hook(int keycode, t_data *data);
int			close_window(t_data *data);
int			mouse_func(int button, int x, int y, t_data *data);
void		set_error(void);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		verify_line_command(t_data *data);
void		message_error(void);
void		select_fractol(t_data *data);
void		verify_arguments(char *data);

#endif
