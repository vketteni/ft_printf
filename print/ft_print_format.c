/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:56:56 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/16 02:11:10 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_format(t_format_field *field, va_list args)
{
	int		count;
	va_list	args_copy;

	va_copy(args_copy, args);
	count = 0;
	if (!(field->flag_left_justify))
		count += ft_print_padding(field, args_copy);
	if (field->specifier == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (field->specifier == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (field->specifier == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (field->specifier == 'd' || field->specifier == 'i')
		count += ft_print_int(va_arg(args, int), field->flag_always_sign);
	else if (field->specifier == 'u')
		count += ft_print_int_unsigned(va_arg(args, unsigned int));
	else if (field->specifier == 'x' || field->specifier == 'X')
		count += ft_print_hex(va_arg(args, unsigned int),
				field->flag_alternative_form);
	if (field->flag_left_justify)
		count += ft_print_padding(field, args_copy);
	return (count);
}
