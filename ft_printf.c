/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:37:37 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/13 19:41:44 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	handle_format(const char *format, int *count, va_list args)
{
	t_format_field	field;

	if (*format == '%')
	{
		*count += ft_print_char('%');
		return (1);
	}
	ft_get_specifier(format, &field);
	if (!ft_check_validity(format, &field))
		return (0);
	ft_get_flags(format, &field);
	ft_get_min_width(format, &field, args);
	if (field.specifier == 's')
		ft_get_precision(format, &field, args);
	*count += ft_print_format(&field, args);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format != '%')
			count += ft_print_char(*format);
		else
		{
			format++;
			if (handle_format(format, &count, args) == 0)
			{
				va_end(args);
				return (count);
			}
			while (!ft_is_format_specifier(*format))
				format++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
