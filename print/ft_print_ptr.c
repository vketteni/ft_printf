/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:11:12 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/22 00:47:34 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_ptr(void *p)
{
	long unsigned	ptr;

	ptr = (long unsigned)p;
	if (!p)
		return (ft_print_str("0x0"));
	else
		return (ft_print_hex(ptr, 0, 1));
}
