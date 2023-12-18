/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format_field_attributes.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:51:06 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/18 19:11:31 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

t_format_field	*ft_get_format_field_attributes(const char *format,
		t_format_field *field, va_list *args)
{
	ft_get_specifier(format, field);
	if (field == 0)
		return (0);
	ft_get_flags(format, field);
	if (field == 0)
		return (0);
	ft_get_min_width(format, field, args);
	if (field == 0)
		return (0);
	if (field->specifier == 's')
	{
		ft_get_precision(format, field, args);
		if (field == 0)
			return (0);
	}
	return (field);
}