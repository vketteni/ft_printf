/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:12:55 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/16 02:11:17 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_int(int num, int show_sign)
{
	int	count;

	count = 0;
	if (show_sign)
		count += ft_print_char('+');
	ft_putnbr_fd(num, 1);
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}
