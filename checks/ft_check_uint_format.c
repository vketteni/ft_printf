/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_uint_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:26:50 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/22 14:31:21 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

static const char	*ft_check_flag_combination(const char *format)
{
	t_format_field	*field;

	field = ft_initialize_format_field();
	while (ft_is_flag(*format))
	{
		if (*format == '0')
			field->flag_zero_padding = 1;
		else if (*format == '-')
			field->flag_left_justify = 1;
		format++;
	}
	if (field->flag_left_justify && field->flag_zero_padding)
	{
		free(field);
		return (0);
	}
	free(field);
	return (format);
}

const char	*ft_check_uint_format(const char *format)
{
	const char	*valid_format;

	valid_format = format;
	if (!ft_check_flag_combination(format))
		return (0);
	while (ft_is_flag(*format))
	{
		if (*format == '#' || *format == '+')
			return (0);
		format++;
	}
	while (ft_isdigit(*format))
		format++;
	if (*format == '.')
		format++;
	else if (*format != 'u')
		return (0);
	while (ft_isdigit(*format))
		format++;
	if (*format != 'u')
		return (0);
	return (valid_format);
}
