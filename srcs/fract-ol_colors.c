/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:14:51 by microdri          #+#    #+#             */
/*   Updated: 2022/09/26 18:46:13 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	get_colors(int number_of_iterations)
{
	int h;
	int s;
	int v;
	int color;

	h = 255 * number_of_iterations / MAX_ITERATION;
    s = 1;
	if (number_of_iterations < MAX_ITERATION)
		v = 1;
	else
		v = 0;	
	return(color = hsv_to_hex(h, s, v));
}

int	check_number(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}	

int	hsv_to_hex(int h, int s, int v)
{
	int max;
	int min;
	int z;
	int	rgb;

	max = 255 * v;
	min = max * (1 - s);
	z	= (max - min) * (1 - check_number((h / 60) % 2 - 1));
	rgb = 0;	
	if (h >= 0 && h < 60)
		rgb = max << 16 | (z + min) << 8 | min;
	if (h >= 60 && h < 120)
		rgb = (z + min) << 16 | max << 8 | min;
	if (h >= 120 && h < 180)
		rgb = min << 16 | max << 8 | (z + min);
	if (h >= 180 && h < 240)
		rgb = min << 16 | (z + min) << 8 | max;
	if (h >= 240 && h < 300)
		rgb = (z + min) << 16 | min << 8 | max;
	if (h >= 300 && h < 360)
		rgb = max << 16 | min << 8 | (z + min);
	
	return (rgb);		
}


