/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:55:26 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/07 18:17:21 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

void	ft_get_width(char *format, t_format_field *field, va_list args)
{
    while (ft_is_flag(*format))
        format++;
    if (*format == '*')
        field->width = va_arg(args, int);
    else
        field->width = ft_atoi(*format);  

}