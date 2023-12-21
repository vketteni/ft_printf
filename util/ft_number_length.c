/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:36:37 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/20 13:42:45 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_number_length(unsigned long nbr, int base)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}