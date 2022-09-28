/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:33:11 by microdri          #+#    #+#             */
/*   Updated: 2022/09/28 11:29:58 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int message_error(int argc, char **argv, t_data *img, t_window window)
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
    examples_of_set_julia   = "examples for set julia -> -0.79 0.15 | -0.162 1.04 | 0.3 0.1 | -1.476 0 | -0.12 0.77 | 0.28 0.008";

    if (argc == 1 || argc == 3 || argc >= 5 || verify_line_command(argv, img, window) != 1)
    {
		ft_putstr_fd("Invalid parameter, try!\n", 2);
        ft_printf("%s\t%s\n", message_mandelbrot, mandelbrot_set);
        ft_printf("%s\t%s\n", message_julia, julia_set);
        ft_printf("%s\n", examples_of_set_julia);
    }
	else
		return (0);
    return (1);
}
