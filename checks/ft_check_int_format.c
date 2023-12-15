/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:24:48 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/15 14:52:28 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

static int ft_check_flag_combination(const char *format)
{
	int	flag_zero_padding;
	int flag_always_sign;
	int	flag_left_justify;
	int flag_starts_with_blank;

	while (ft_is_flag(*format))
	{
		if (*format == '0')
			flag_zero_padding = 1;
		if (*format == '+')
			flag_always_sign = 1;
		if (*format == '-')
			flag_left_justify = 1;
		if (*format == ' ')
			flag_starts_with_blank = 1;
		if (flag_always_sign && flag_starts_with_blank)
			return (0); 
		if (flag_left_justify && flag_zero_padding)
			return (0);
			
		format++;
	}
	return (1);
}

int    ft_check_int_format(const char *format)
{
	if (!ft_check_flag_combination(format))
		return (0);
    while (ft_is_flag(*format))
	{
        if (*format == '#')
            return (0);
        format++;
    }
	while (ft_isdigit(*format))
		format++;
	if (*format == 'd' || *format == 'i')
		return (1);
	else if (*format == '.')
		format++;
	while (ft_isdigit(*format))
		format++;
	if (*format == 'd' || *format == 'i')
		return (1);
    return (0);
}

