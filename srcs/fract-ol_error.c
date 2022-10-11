/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:33:11 by microdri          #+#    #+#             */
/*   Updated: 2022/10/11 16:20:01 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void message_error(void)
{
    char    *message_mandelbrot;
    char    *message_julia;
    char    *mandelbrot_set;
    char    *julia_set;
    char    *examples_of_set_julia;
 
	message_mandelbrot      = "For mandelbrot set: ";
    message_julia           = "For julia set: ";
    mandelbrot_set          = "./fractol mandelbrot";
    julia_set               = "./fractol julia set set ";
    examples_of_set_julia   = "examples for set julia -> -0.79 0.15 | -0.162 1.04 | 0.3 0.01 | -1.476 0 | -0.12 0.77 | 0.28 0.008";

	ft_putstr_fd("Invalid parameter, try!\n", 2);
    ft_printf("%s\t%s\n", message_mandelbrot, mandelbrot_set);
    ft_printf("%s\t%s\n", message_julia, julia_set);
    ft_printf("%s\n", examples_of_set_julia);
}

void	set_error(void)
{
	message_error();
	exit(0);
}

void verify_line_command(t_data *data) 
{
	int size;

	size = ft_strlen(data->argv[1]);
	if (data->argc < 2 || data->argc == 3 || data->argc >= 5)
		set_error();
	if (ft_strnstr(data->argv[1], "mandelbrot", 10) && size != 10)
		set_error();
	if (ft_strnstr(data->argv[1], "julia", 5) && size != 5)
		set_error();
	if (!ft_strnstr(data->argv[1], "mandelbrot", 10) && !ft_strnstr(data->argv[1], "julia", 5))
		set_error(); 
	if (data->argc < 4 && !ft_strnstr(data->argv[1], "mandelbrot", 10))
		set_error();
}

void verify_arguments(char *data)
{
	int index;
	int dot;

	index = 0;
	dot = 0;
	while (data[index] != '\0')
	{	
		if (data[index] == '.')
			dot++;
		else if (data[index] < '0' || data[index] > '9')
			set_error();		
		index++;
	}
	if (dot > 1)
		set_error();
}
