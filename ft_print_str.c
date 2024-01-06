/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:10:49 by vincentkett       #+#    #+#             */
/*   Updated: 2024/01/06 18:15:02 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:56:56 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/22 14:35:52 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int	*ft_specified_printer(t_format_field *field, va_list *args,
		int *count)
{
	if (field->specifier == 'c')
		*count += ft_print_char(va_arg(*args, int));
	else if (field->specifier == 's')
		*count += ft_print_str(va_arg(*args, char *));
	else if (field->specifier == 'p')
		*count += ft_print_ptr(va_arg(*args, void *));
	else if (field->specifier == 'd' || field->specifier == 'i')
		*count += ft_print_dec((long)va_arg(*args, int), field);
	else if (field->specifier == 'u')
		*count += ft_print_dec((long)va_arg(*args, unsigned int), field);
	else if (field->specifier == 'x')
		*count += ft_print_hex(va_arg(*args, unsigned int), 0,
				field->flag_alternative_form);
	else if (field->specifier == 'X')
		*count += ft_print_hex(va_arg(*args, unsigned int), 1,
				field->flag_alternative_form);
	return (count);
}

static int	*ft_print_specified_format(t_format_field *field, va_list *args,
		int *count)
{
	int		padding;
	char	p;

	padding = ft_calculate_padding(field->min_width, field->specifier, args);
	if (field->flag_zero_padding)
		p = '0';
	else
		p = ' ';
	while (!(field->flag_left_justify) && padding--)
		*count += ft_print_char(p);
	ft_specified_printer(field, args, count);
	while (field->flag_left_justify && padding--)
		*count += ft_print_char(' ');
	return (count);
}

static const char	*ft_process_format_specifier(const char *format,
		int *print_count, va_list *args)
{
	t_format_field	*field;
	va_list			args_copy;

	field = ft_initialize_format_field();
	if (field == 0)
	{
		free(field);
		return (0);
	}
	if (*format == '%')
		*print_count += ft_print_char('%');
	else
	{
		va_copy(args_copy, *args);
		field = ft_get_format_field_attributes(format, field, &args_copy);
		if (field == 0)
		{
			free(field);
			return (0);
		}
		va_end(args_copy);
		ft_print_specified_format(field, args, print_count);
	}
	free(field);
	return (format);
}

static const char	*ft_process_printing(const char *format, int *print_count,
		va_list *args)
{
	if (*format != '%')
		*print_count += ft_print_char(*format);
	else
	{
		format = ft_process_format_specifier(++format, print_count, args);
		if (format == 0)
			return (0);
		while (!ft_is_format_specifier(*format))
			format++;
	}
	return (format);
}

int	ft_print_format_string(const char *format, va_list *args)
{
	int	*print_count;
	int	result_count;

	print_count = ft_initialize_print_count();
	if (print_count == 0)
		return (0);
	while (*format)
	{
		format = ft_process_printing(format, print_count, args);
		if (format == 0)
			break ;
		format++;
	}
	result_count = *print_count;
	free(print_count);
	return (result_count);
}


int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		str = "(null)";
		while (*str)
			count += ft_print_char(*str++);
	}
	else
	{
		while (*(str))
			count += ft_print_char(*(str++));
	}
	return (count);
}
