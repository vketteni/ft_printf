/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_to_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:34:06 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/06 21:42:09 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
int	ft_base_to_decimal(char *src, int base)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (*(src + i))
	{
		if (n == 0)
		{
			if (ft_isdigit(*(src + i)))
				n = *(src + i) - '0';
			else
				n = ft_toupper(*(src + i)) - 'A' + 10;
		}
		else
		{
			if (ft_isdigit(*(src + i)))
				n = (n * base) + *(src + i) - '0';
			else
				n = (n * base) + ft_toupper(*(src + i)) - 'A' + 10;
		}
		i++;
	}
	return (n);
	
}
