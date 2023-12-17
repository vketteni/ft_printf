/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:26:33 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/16 01:47:37 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

int	ft_check_str_format(const char *format)
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
	else if (*format != 's')
		return (0);
	while (ft_isdigit(*format))
		format++;
	if (*format != 's')
		return (0);
	return (1);
}
