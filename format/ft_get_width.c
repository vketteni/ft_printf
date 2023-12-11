/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:55:26 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/10 01:50:27 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

t_format_field	*ft_get_width(const char *format, t_format_field *field, va_list args)
{
    while (ft_is_flag(*format))
        format++;
    if (*format == '*')
        field->width = va_arg(args, int);
    else
        field->width = ft_atoi(format);  
    return (field);
}