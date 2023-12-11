/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:44:00 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/09 23:54:40 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

int	ft_check_validity(const char *format, t_format_field *field)
{
	if (field->specifier == 'c')
		return (ft_check_char_format(format));
	else if (field->specifier == 's')
		return (ft_check_str_format(format));
	else if (field->specifier == 'p')
		return (ft_check_ptr_format(format));
	else if (field->specifier == 'd' || field->specifier == 'i')
		return (ft_check_int_format(format));
	else if (field->specifier == 'u')
		return (ft_check_uint_format(format));
	else if (field->specifier == 'x')
		return (ft_check_hexlc_format(format));
	else if (field->specifier == 'X')
		return (ft_check_hexuc_format(format));
	else
		return (0);
}
