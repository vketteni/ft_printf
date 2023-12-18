/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_padding.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:58:28 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/18 18:35:42 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int	ft_specified_arg_len(char specifier, va_list args)
{
	if (specifier == 'c')
		return (1);
	else if (specifier == 's')
		return (ft_strlen(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_strlen(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_strlen(ft_itoa(va_arg(args, int))));
	else if (specifier == 'u')
		return (ft_strlen(ft_itoa(va_arg(args, unsigned int))));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_strlen(ft_itoa(va_arg(args, unsigned int))));
	else
		return (0);
}

int	ft_calculate_padding(int min_width, char specifier, va_list *args)
{
	int		arg_len;
	int		padding;
	va_list	args_copy;

	va_copy(args_copy, *args);
	arg_len = ft_specified_arg_len(specifier, args_copy);
	padding = 0;
	while ((min_width--) > arg_len)
		padding++;
	return (padding);
}