/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:44:00 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/07 18:17:21 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

int	ft_check_validity(char *format, t_format_field *field)
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
		return (ft_check_lchex_format(format));
	else if (field->specifier == 'X')
		return (ft_check_uphex_format(format));
}
