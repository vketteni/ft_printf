/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_print_count.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:39:14 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/18 12:46:38 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	*ft_initialize_print_count(void)
{
	int *print_count;

	print_count = (int *)malloc(sizeof(int));
	if (print_count == 0)
		return (0);
	*print_count = 0;
	return (print_count);
}
