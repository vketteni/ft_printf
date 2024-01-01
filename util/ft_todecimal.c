/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_todecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:39:48 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/01 01:42:22 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_todecimal(char *src, int base)
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
