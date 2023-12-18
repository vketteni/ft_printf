/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 02:09:30 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/18 14:01:39 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

t_format_field	*ft_get_min_width(const char *format, t_format_field *field,
		va_list *args)
{
	while (ft_is_flag(*format))
		format++;
	if (*format == '*')
		field->min_width = va_arg(*args, int);
	else
		field->min_width = ft_atoi(format);
	return (field);
}
