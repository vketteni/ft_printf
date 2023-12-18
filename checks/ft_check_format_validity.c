/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specified_format.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:44:00 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/17 22:49:17 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

static const char	*ft_check_specified_format(const char *format, char specifier)
{
	if (specifier == 'c')
		return (ft_check_char_format(format));
	else if (specifier == 's')
		return (ft_check_str_format(format));
	else if (specifier == 'p')
		return (ft_check_ptr_format(format));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_check_int_format(format));
	else if (specifier == 'u')
		return (ft_check_uint_format(format));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_check_hex_format(format));
	else
		return (0);
}

static const char	*ft_process_validation(const char *format)
{
	int		i;
	char	specifier;

	i = 1;
	if (*format == '%')
	{
		while (!ft_is_format_specifier(*(format + i)))
			i++;
		if (*(format + i))
			specifier = *(format + i);
		else 
			return (0);
		if (ft_check_specified_format(++format, specifier))
			return (format);
		else
			return (0);
	}
	return (format);
}
const char	*ft_check_format_validity(const char *format)
{
	const char	*valid_format;

	valid_format = format;
	while (*format)
	{
		format = ft_process_validation(format);
		if (format == 0)
			return (0);
		format++;
	}
	return (valid_format);
}

