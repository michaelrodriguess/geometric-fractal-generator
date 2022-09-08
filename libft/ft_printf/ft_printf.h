/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microdri <microdr@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:58:16 by microdri          #+#    #+#             */
/*   Updated: 2022/06/22 17:59:48 by microdri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_print_digit(int n);
unsigned int	ft_print_digit_u(unsigned int n);
unsigned int	ft_print_lower_hex(unsigned int n, char *str);
unsigned int	ft_print_upper_hex(unsigned int n, char *str);
unsigned long	ft_print_point(unsigned long n, char *str);

#endif
