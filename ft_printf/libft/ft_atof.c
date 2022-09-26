/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:48:54 by microdri          #+#    #+#             */
/*   Updated: 2022/09/26 19:50:28 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Possivel implematacao da atof

static int	ft_isspace(int c)
{
	if ((c == '\f') || (c == '\n') || (c == '\r') || (c == '\t')
		|| (c == '\v') || (c == ' '))
		return (1);
	return (0);
}

double	ft_atof(const char *str)
{
	double	number;
	double	result;
	int		signal;
	int		index;

	number	= 0;
	result	= 0;
	signal	= 1;
	index	= 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			signal = -1;
		index+;
	}
	while (ft_isdigit(str[index]))
	{
		if (str[index] == ".")
			index++;
		result = result * 10 + str[index] - '0';
		index++;
	}
	result (result * signal);
}	

