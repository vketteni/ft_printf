/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_print_counter.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:39:14 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/18 12:44:46 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	*ft_initialize_print_counter(void)
{
	int *print_counter;

	print_counter = (int *)malloc(sizeof(int));
	if (print_counter == 0)
		return (0);
	return (print_counter);
}
