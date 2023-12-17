/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hex_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:26:00 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/16 01:46:48 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

static int	ft_check_flag_combination(const char *format)
{
	int	flag_zero_padding;
	int	flag_left_justify;

	while (ft_is_flag(*format))
	{
		if (*format == '0')
			flag_zero_padding = 1;
		if (*format == '-')
			flag_left_justify = 1;
		if (flag_left_justify && flag_zero_padding)
			return (0);
		format++;
	}
	return (1);
}

int	ft_check_hex_format(const char *format)
{
	if (!ft_check_flag_combination(format))
		return (0);
	while (ft_is_flag(*format))
	{
		if (*format == ' ' || *format == '+')
			return (0);
		format++;
	}
	while (ft_isdigit(*format))
		format++;
	if (*format == '.')
		format++;
	else if (*format != 'x' || *format != 'X')
		return (0);
	while (ft_isdigit(*format))
		format++;
	if (*format != 'x' || *format != 'X')
		return (0);
	return (1);
}
