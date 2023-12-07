/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:37:37 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/07 18:15:11 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_string(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		print_char(*str);
		i++;
	}
	return (i);
}

int	print_int(int num)
{
}

int	print_pointer(void *p)
{
}

int	print_hexa_lowercase(unsigned int d)
{
}

int	print_hexa_uppercase(unsigned int d)
{
}

int	print_unsigned(unsigned int d)
{
}

int	ft_print_format (char *format, t_format_field *field, va_list args)
{
	int	count;

	count = 0;
	if (field->specifier == 'c')
		count += print_char(va_arg(args, int));
	else if (field->specifier == 's')
		count += print_string(va_arg(args, char *));
	else if (field->specifier == 'p')
		count += print_pointer(va_arg(args, void *));
	else if (field->specifier == 'd' || field->specifier == 'i')
		count += print_int(va_arg(args, int));
	else if (field->specifier == 'u')
		count += print_unsigned(va_arg(args, unsigned int));
	else if (field->specifier == 'x')
		count += print_hexa_lowercase(va_arg(args, void *));
	else if (field->specifier == 'X')
		count += print_hexa_uppercase(va_arg(args, void *));
	return (count);
}

int	handle_format(char *format, int *count, va_list args)
{
	t_format_field	field;

	if (*format == '%')
	{
		*count += print_char('%');
		return (1);
	}
	field.specifier = ft_get_specifier(format);
	if (!ft_check_validity(format, &field))
		return (0);
	ft_get_flags(format, &field);
	ft_get_width(format, &field, args);
	if (field.specifier == 's')
		ft_get_precision(format, &field, args);
	*count += ft_print_format(format, &field, args);
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
			count += print_char(*format);
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

int	main(void)
{
	ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
	return (0);
}
