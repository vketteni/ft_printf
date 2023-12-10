/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:15:24 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/10 02:10:43 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

t_format_field  *ft_get_precision(char *format, t_format_field *field, va_list args)
{
    while (ft_is_flag(*format))
        format++;
	while (ft_isdigit(*format))
		format++;
	if (*format == '.')
    {
        format++;
        if (*format == '*')
            field->precision = va_arg(args, int);
        else
            field->precision = ft_atoi(format);  
    }
    return (field);
}