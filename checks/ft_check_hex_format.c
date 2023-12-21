/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hex_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:26:00 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/20 12:59:07 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

static const char	*ft_check_flag_combination(const char *format)
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
	return (format);
}

const char	*ft_check_hex_format(const char *format)
{
	const char	*valid_format;

	valid_format = format;
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
	else if (*format == 'x' || *format == 'X')
		return (valid_format);
	while (ft_isdigit(*format))
		format++;
	if (*format == 'x' || *format == 'X')
		return (valid_format);
	return (0);
}
