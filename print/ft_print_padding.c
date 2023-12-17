/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:47:02 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/16 02:10:47 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_padding(t_format_field *field, va_list args)
{
	int	padding;
	int	count;

	padding = field->min_width;
	if (field->specifier == 'c')
		padding -= 1;
	else if (field->specifier == 's')
		padding -= ft_strlen(va_arg(args, char *));
	else if (field->specifier == 'p')
		padding -= ft_strlen(va_arg(args, void *));
	else if (field->specifier == 'd' || field->specifier == 'i')
		padding -= ft_strlen(ft_itoa(va_arg(args, int)));
	else if (field->specifier == 'u')
		padding -= ft_strlen(ft_itoa(va_arg(args, unsigned int)));
	else if (field->specifier == 'x' || field->specifier == 'X')
		padding -= ft_strlen(ft_itoa(va_arg(args, unsigned int)));
	if (padding == 0 || padding < 0)
		padding = 0;
	count = padding;
	while (padding--)
		ft_print_char(' ');
	return (count);
}
