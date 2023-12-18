/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:37:37 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/18 17:08:20 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	ft_printf(const char *format, ...)
{
	int		print_count;
	va_list	args;

	if (format == 0)
		return (0);
	print_count = 0;
	va_start(args, format);
	format = ft_check_format_validity(format);
	if (format != 0)
		print_count = ft_print_format_string(format, &args);
	va_end(args);
	return (print_count);	
}	



