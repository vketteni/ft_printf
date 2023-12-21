/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_padding.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:58:28 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/20 14:14:54 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static int	ft_specified_arg_len(char specifier, va_list args)
{
	long	di;

	if (specifier == 'c')
		return (1);
	else if (specifier == 's')
		return (ft_strlen(va_arg(args, char *)));
	else if (ft_strchr("pxX", specifier))
	{
		if (specifier == 'p')
			return (ft_number_length((unsigned long)va_arg(args, void *), 16) + 2);
		else 
			return (ft_number_length((unsigned long)va_arg(args, unsigned int), 16));
	}
	else if (ft_strchr("diu", specifier))
	{
		if (specifier == 'u')
			return ((unsigned long)ft_number_length(va_arg(args, unsigned int), 10));
		else
		{
			di = va_arg(args, int);
			return (ft_number_length((unsigned long)ft_absolute(di), 10));
		}
	}
	return (-1);
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