/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:13:52 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/20 13:03:34 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_hex(unsigned long hex, int uppercase)
{
	int		i;	
	int		count;
	char	*hexadecimal;

	i = 0;
	hexadecimal = ft_tobase(hex, 16);
	count = 0;
	if (uppercase)
		count += ft_print_str(hexadecimal);
	else
	{
		while (hexadecimal[i])
			count += ft_print_char(ft_tolower(hexadecimal[i++]));
	}
	free(hexadecimal);
	return (count);
}
