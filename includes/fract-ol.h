/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:53:10 by microdri          #+#    #+#             */
/*   Updated: 2022/09/27 12:00:44 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# define MAX_ITERATION 80
# define SIZE_DISPLAY 800

typedef struct n_window
{
	int x;
	int y;
}	t_window;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct n_complex
{
	double r;
	double i;
}	t_complex;

double		value_absolute(t_complex z);
t_complex	complex_add(t_complex s_a, t_complex s_b);
t_complex	complex_pow(t_complex p);
int			get_iteration_mandelbrot(t_complex c);
int			get_iteration_julia(t_complex c, t_complex z);
void		fractol_mandelbrot(t_data *img, t_window window);
void		fractol_julia(t_data *img, t_window window);
int			get_colors(int number_of_iterations);
int			check_number(int n);
int			hsv_to_hex(int h, int s, int v);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			verify_line_command(char **argv,t_data *img, t_window window);
int			message_error(int argc, char **argv, t_data *img, t_window window);


#endif
