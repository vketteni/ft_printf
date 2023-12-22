/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:39:31 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/22 13:19:12 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

t_format_field	*ft_get_flags(const char *format, t_format_field *field)
{
	while (ft_is_flag(*format))
	{
		if (*format == '-')
			field->flag_left_justify = 1;
		else if (*format == '#')
			field->flag_alternative_form = 1;
		else if (*format == ' ')
			field->flag_starts_with_blank = 1;
		else if (*format == '0')
			field->flag_zero_padding = 1;
		else if (*format == '+')
			field->flag_always_sign = 1;
		format++;
	}
	return (field);
}
