/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:13:52 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/22 00:47:17 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_hex(unsigned long hex, int uppercase, int flag_alternative_form)
{
	int		i;
	int		count;
	char	*hexadecimal;

	count = 0;
	if (flag_alternative_form && uppercase)
		count += ft_print_str("0X");
	if (flag_alternative_form && !uppercase)
		count += ft_print_str("0x");
	if (hex == 0)
		return (ft_print_char('0') + count);
	hexadecimal = ft_tobase(hex, 16);
	if (uppercase)
		count += ft_print_str(hexadecimal);
	else
	{
		i = 0;
		while (hexadecimal[i])
			count += ft_print_char(ft_tolower(hexadecimal[i++]));
	}
	free(hexadecimal);
	return (count);
}
