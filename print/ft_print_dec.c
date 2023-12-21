/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:12:55 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/20 15:38:38 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_dec(long dec, int show_sign)
{
	int	count;

	count = 0;
	if (show_sign)
		count += ft_print_char('+');
	ft_putnbr_fd(dec, 1);
	if (dec == 0)
		count++;
	else
	{
		if (dec < 0)
			count++;
		while (dec)
		{
			dec /= 10;
			count++;
		}
	}
	return (count);
}
