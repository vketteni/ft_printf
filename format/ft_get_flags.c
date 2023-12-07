/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:39:31 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/07 18:21:53 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

void	ft_get_flags(char *format, t_format_field *field)
{
	while (ft_is_flag(*format))
	{
		if (*format == '-')
			field->flag_left_justify = true;
		else if (*format == '#')
			field->flag_alternative_form = true;
		else if (*format == ' ')
			field->flag_starts_with_blank = true;
		else if (*format == '0')
			field->flag_zero_padding = true;
		format++;
	}
}
