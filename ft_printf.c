/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:37:37 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/10 02:07:45 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		ft_print_char(*str);
		i++;
	}
	return (i);
}

int	ft_print_int(int num)
{
	int i;

	i = 0;
	ft_putnbr_fd(num, 1);
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_print_pointer(void *p)
{
	return (1);
}

int	ft_print_hexa_lowercase(unsigned int d)
{
	return (1);
}

int	ft_print_hexa_uppercase(unsigned int d)
{
	return (1);
}

int	ft_print_unsigned(unsigned int d)
{
	return (1);
}

int	ft_print_format (char *format, t_format_field *field, va_list args)
{
	int	count;

	count = 0;
	if (field->specifier == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (field->specifier == 's')
		count += ft_print_string(va_arg(args, char *));
	else if (field->specifier == 'p')
		count += ft_print_pointer(va_arg(args, void *));
	else if (field->specifier == 'd' || field->specifier == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (field->specifier == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (field->specifier == 'x')
		count += ft_print_hexa_lowercase(va_arg(args, unsigned int));
	else if (field->specifier == 'X')
		count += ft_print_hexa_uppercase(va_arg(args, unsigned int));
	return (count);
}

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
	ft_get_width(format, &field, args);
	if (field.specifier == 's')
		ft_get_precision(format, &field, args);
	*count += ft_print_format(format, &field, args);
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

int	main(void)
{
	ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
	return (0);
}
