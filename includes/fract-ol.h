/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:53:10 by microdri          #+#    #+#             */
/*   Updated: 2022/10/04 15:23:11 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# define MAX_ITERATION 250
# define SIZE_DISPLAY 1080

typedef struct	s_data {
	void	*mlx_ptr;
	void	*mlx_wd;
	void	*img;
	char	*addr;
	int		x;
	int		y;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
}				t_data;

typedef struct s_complex
{
	double r;
	double i;
}	t_complex;

double		value_absolute(t_complex z);
t_complex	complex_add(t_complex s_a, t_complex s_b);
t_complex	complex_pow(t_complex p);
int			get_iteration_mandelbrot(t_complex c);
int			get_iteration_julia(t_complex c, t_complex z);
void		fractol_mandelbrot(t_data *img);
void		fractol_julia(t_data *img, t_complex c);
int			get_colors(int number_of_iterations);
int			check_number(int n);
int			hsv_to_hex(int h, int s, int v);
int			mouse_hook(int button, int x, int y, t_data *data);
int			key_hook(int keycode, t_data *data);
int			close_window(t_data *data);
void		set_error(void);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		verify_line_command(int argc, char **argv);
void		message_error(void);
void		select_fractol(char **argv, t_data img);

#endif
