/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:12:55 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/22 13:01:16 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_dec(long dec, t_format_field *field)
{
	int	count;

	count = 0;
	if (field->flag_always_sign && dec >= 0)
		count += ft_print_char('+');
	else if(field->flag_starts_with_blank && dec >= 0)
		count += ft_print_char(' ');
	count += ft_putnbr_fd(dec, 1);

	return (count);
}
