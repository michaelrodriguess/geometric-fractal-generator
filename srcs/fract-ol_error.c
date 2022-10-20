/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:33:11 by microdri          #+#    #+#             */
/*   Updated: 2022/10/14 19:10:45 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	message_error(void)
{
	ft_putstr_fd ("Invalid parameter!\n", 2);
	ft_putstr_fd ("\t _________________________________________", 2);
	ft_putstr_fd ("______________________________________\n", 2);
	ft_putstr_fd ("\t|\tFor Mandelbrot set:\t|\t", 2);
	ft_putstr_fd ("For Julia set:\t\t\t\t|\n", 2);
	ft_putstr_fd ("\t|\t./fractol mandelbrot\t|\t", 2);
	ft_putstr_fd ("./fractol julia {EXAMPLES BELOW}!\t|\n", 2);
	ft_putstr_fd ("\t|_______________________________|\t\t -0.79\t0.15\t\t\t|\n", 2);
	ft_putstr_fd ("\t\t\t\t\t|\t\t -0.162\t1.04\t\t\t|\n\t\t\t\t\t|\t\t -0.12\t0.77\t\t\t|\n", 2);
	ft_putstr_fd ("\t\t\t\t\t|\t\t -1.476\t0\t\t\t|\n\t\t\t\t\t|\t\t -0.4\t0.59\t\t\t|\n", 2);
	ft_putstr_fd ("\t\t\t\t\t|\t\t -0.54\t0.54\t\t\t|\n\t\t\t\t\t|\t\t  -0.4\t-0.59\t\t\t|\n", 2);
	ft_putstr_fd ("\t\t\t\t\t|\t\t 0.28\t0.008\t\t\t|\n\t\t\t\t\t|\t\t 0.3\t0.01\t\t\t|\n", 2);
	ft_putstr_fd ("\t\t\t\t\t|\t\t 0\t0.08\t\t\t|\n\t\t\t\t\t|\t\t 0.355\t0.355\t\t\t|\n", 2);
	ft_putstr_fd ("\t\t\t\t\t|\tTry this -> 0.355534\t0.337292\t|\n\t\t\t\t\t|", 2);
	ft_putstr_fd ("_______________________________________________|\n", 2);
}

void	set_error(void)
{
	message_error();
	exit(0);
}

void	verify_line_command(t_data *data)
{
	int	size;

	size = ft_strlen(data->argv[1]);
	if (ft_strnstr(data->argv[1], "mandelbrot", 10) && size != 10)
		set_error();
	if (ft_strnstr(data->argv[1], "julia", 5) && size != 5)
		set_error();
	if (!ft_strnstr(data->argv[1], "mandelbrot", 10)
		&& !ft_strnstr(data->argv[1], "julia", 5))
		set_error();
	if (data->argc < 4 && !ft_strnstr(data->argv[1], "mandelbrot", 10))
		set_error();
}

void	verify_arguments(char *data)
{
	int	index;
	int	dot;
	int	signal;

	index = 0;
	dot = 0;
	signal = 0;
	while (data[index] != '\0')
	{	
		if (data[index] == '.')
			dot++;
		else if (data[index] == '-' || data[index] == '+')
			signal++;
		else if (data[index] < '0' || data[index] > '9')
			set_error();
		index++;
	}
	if (dot > 1 || signal > 1)
		set_error();
}
