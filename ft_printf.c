/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:37:37 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/06 16:16:58 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Manage field minimum width
//  %.      ->  Max characters displayed in string conversion
//                          printf(%.5s, "hello world"); Output: "hello"
//  %-      ->  Left-align the output within the specified width field
//                          printf("%-10s", "left"); Output: "left      "
//  %0      ->  Pad numeric values with zeros instead of spaces
//                          printf("%05d", 42); Output: "00042"

//  %#      ->  Used for alternative form.
//              %#x (Hex)   0x prefix added to non-zero values.
//              %#X (Hex)   0X prefix added to non-zero values.
//  %blank  ->  Positive values begin with a blank.
//                          printf("% d", 42); Output: " 42"
//  %+      ->  Forces the inclusion of a sign
//                            printf("%+d", 42); Output: "+42"

//  traverse string
//      if not format
//          print char
//      if '%'
//          traverse until format specifier
//              if flag
//                  save flag
//              else
//                  throw error
//          if flags saved
//              create field
//          print specified format

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

#define true 1
#define false 0

typedef struct s_format_field
{
	int		width;
	int		precision;
	char	specifier;
	int		left_justify;
	int		zero_padding;
	int		always_sign;
	int		alternative_form;
	int		starts_with_blank;
}			t_format_field;

int	ft_is_format_specifier(char c)
{
	if (c == 'd' || c == 'i' || c == 's' || c == 'x' || c == 'X' || c == 'u'
		|| c == 'p' || c == 'c' || c == '%')
		return (1);
	return (0);
}

// Function to print a single character
int	print_char(char c)
{
	return (write(1, &c, 1));
}

// Function to print a string
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

// Function to print an integer
int	print_int(int num)
{
	// Implement the logic to print an integer here
	// You may use the write function to print individual characters
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

char	ft_get_format_specifier(char *format)
{
	while (format && !ft_is_format_specifier(*format))
		format++;
	return (*format);
}

void	ft_get_flags(char *format, t_format_field *field)
{
	//	HANDLE FLAGS
	while (ft_is_flag(**format))
	{
		if (**format == '-')
			field->left_justify = true;
		else if (**format == '#')
			field->alternative_form = true;
		else if (**format == ' ')
			field->starts_with_blank = true;
		else if (**format == '0')
			field->zero_padding = true;
		*format++;
	}
}

void	ft_get_width(char *format, t_format_field *field)
{
	//	HANDLE FIELD WIDTH
	field->width = ft_atoi(**format);
	while (ft_isdigit(**format))
		*format++;
	//	HANDLE STRING PRECISION (CHAR MAX)
	if (ft_is_precision(**format))
		field->precision = ft_atoi(++(*format));
	while (ft_isdigit(**format))
		*format++;
}

void	ft_check_format_validity(char *format, t_format_field *field)
{
}

int	ft_print_format(char **format, t_format_field *field, va_list args)
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
	else if (field->specifier == '%')
		count += print_char('%');
	return (count);
}

// Function to handle the format specifier and print accordingly
void	handle_format(char *format, int *print_count, va_list args)
{
	t_format_field	field;

	field.specifier = ft_get_format_specifier(format);
	ft_check_format_validity(format, &field);
	ft_get_flags(format, &field);
	ft_get_width(format, &field);
	if (field.specifier == 's')
		ft_get_string_precision(format, &field);
	*print_count += ft_print_format(format, &field, args);
}

// Main printf function
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_count;

	va_start(args, format);
	print_count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			print_count++;
		}
		else
		{
			handle_format(&format, &print_count, args);
		}
		format++;
	}
	va_end(args);
	return (print_count);
}

int	main(void)
{
	ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
	return (0);
}
