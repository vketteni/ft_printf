/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ptr_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:26:20 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/16 01:47:30 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

int	ft_check_ptr_format(const char *format)
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
	else if (*format != 'p')
		return (0);
	while (ft_isdigit(*format))
		format++;
	if (*format != 'p')
		return (0);
	return (1);
}
