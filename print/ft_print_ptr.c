/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:11:12 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/20 14:45:01 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_ptr(void *p)
{
	long unsigned	ptr;
	int				count;

	ptr = (long unsigned)p;
	count = 0;
	if (!p)
		count += ft_print_str("0x0");
	else
	{
		count += ft_print_str("0x");
		count += ft_print_hex(ptr, 0);
	}
	return (count);
}

