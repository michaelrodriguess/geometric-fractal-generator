/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:33:11 by microdri          #+#    #+#             */
/*   Updated: 2022/10/04 12:22:55 by microdri         ###   ########.fr       */
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

void verify_line_command(int argc, char **argv) 
{
	int size;

	size = ft_strlen(argv[1]);
	if (argc < 2)
		set_error();
	if (ft_strnstr(argv[1], "julia", 5) && size != 5)
		set_error();
	if (ft_strnstr(argv[1], "mandelbrot", 10) && size != 10)
		set_error();
	if (!ft_strnstr(argv[1], "mandelbrot", 10) && !ft_strnstr(argv[1], "julia", 5))
		set_error(); 
	if (argc < 4 && !ft_strnstr(argv[1], "mandelbrot", 10))
		set_error();
}

