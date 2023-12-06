/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:37:37 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/06 03:40:20 by vincentkett      ###   ########.fr       */
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
	int	width;
	int	precision;
	int	left_justify;
	int	zero_padding;
	int	always_sign;
	int	alternative_form;
	int	starts_with_blank;
}		t_format_field;

// Function to print a single character
void	print_char(char c)
{
	write(1, &c, 1);
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

// Function to handle the format specifier and print accordingly
void	handle_format(char **format, int *print_count, va_list args)
{
	t_format_field	field;

	while (ft_is_flag(**format))
	{
		if (**format == '-')
			field.left_justify = true;
		else if (**format == '#')
			field.alternative_form = true;
		else if (**format == ' ')
			field.starts_with_blank = true;
		else if (**format == '0')
			field.zero_padding = true;
		*format++;
	}
	field.width = ft_atoi(**format);
	while (ft_isdigit(**format))
		*format++;
	if (ft_is_precision(**format))
		field.precision = ft_atoi(++(*format));
	while (ft_isdigit(**format))
		*format++;
	if (**format == 'c')
	{
		print_char(va_arg(args, int));
		*print_count++;
	}
	else if (**format == 's')
		print_count += print_string(va_arg(args, char *));
	else if (**format == 'p')
		print_count += print_pointer(va_arg(args, void *));
	else if (**format == 'd' || **format == 'i')
		print_count += print_int(va_arg(args, int));
	else if (**format == 'u')
		print_count += print_unsigned(va_arg(args, unsigned int));
	else if (**format == 'x')
		print_count += print_hexa(va_arg(args, void *));
	switch (**format)
	{
	case 'c':
		break ;
	case 's':
		*print_count += print_string(va_arg(args, char *));
		break ;
	case 'p':
		// Implement logic to print a pointer in hexadecimal format
		*print_count += print_pointer(va_arg(args, void *));
		break ;
	case 'd':
	case 'i':
		*print_count += print_int(va_arg(args, int));
		break ;
		// Implement cases for 'u', 'x', 'X', and '%'
		// ...
	case 'u':
	case 'x':
	case 'X':
	case '%':
	default:
		// Handle unsupported format specifier or throw an error
		break ;
	}
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
	// You may return the total number of characters printed
}

int	main(void)
{
	ft_printf("Hello, %s! The answer is %d.\n", "world", 42);
	return (0);
}
