/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:39:31 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/12 21:33:00 by vincentkett      ###   ########.fr       */
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
		format++;
	}
	return (field);
}
