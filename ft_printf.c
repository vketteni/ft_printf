/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:37:37 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/14 14:20:14 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		print_count;
	va_list	args;

	if (format == 0)
		return (0);
	va_start(args, format);
	print_count = ft_print_format_string(format, &args);
	va_end(args);
	return (print_count);
}

/* 

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf(" '%d' \n",
	ft_printf(" '%p' \n", (void *)0));

	return (0);
}

// cc -Wall -Werror -Wextra *.c

*/