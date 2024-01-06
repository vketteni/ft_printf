/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:28:38 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/06 21:47:00 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_after_base_change(long unsigned decimal, int base)
{
	int	len;

	len = 0;
	while (decimal)
	{
		decimal /= base;
		len++;
	}
	return (len);
}

char	*ft_decimal_to_base(unsigned long decimal, int base)
{
	unsigned long		quotient;
	unsigned long		remainder;
	int		len;
	char	*res;

	quotient = decimal;
	len = ft_len_after_base_change(decimal, base);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len--] = '\0';
	while (quotient && len > -1)
	{
		remainder = quotient % base;
		quotient = quotient / base;
		if (remainder < 10)
			res[len--] = remainder + '0';
		else
			res[len--] = remainder + 'A' - 10 ;
	}
	return (res);
}
