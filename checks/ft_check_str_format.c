/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:26:33 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/18 19:02:27 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

const char	*ft_check_str_format(const char *format)
{
	const char	*valid_format;

	valid_format = format;
	while (ft_is_flag(*format))
	{
		if (*format != '-')
			return (0);
		format++;
	}
	while (ft_isdigit(*format))
		format++;
	if (*format == '.')
		format++;
	else if (*format != 's')
		return (0);
	while (ft_isdigit(*format))
		format++;
	if (*format != 's')
		return (0);
	return (valid_format);
}
