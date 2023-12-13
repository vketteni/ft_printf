/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:57:48 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/13 20:39:18 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

int    ft_check_char_format(const char *format)
{
    while (ft_is_flag(*format))
	{
        if (*format != '-')
            return (0);
        format++;
    }
	while (ft_isdigit(*format))
		format++;
	if (*format == '.')
		format++;
	else if (*format != 'c')
		return (0);
	while (ft_isdigit(*format))
		format++;
	if (*format != 'c')
		return (0);
    return (1);
}