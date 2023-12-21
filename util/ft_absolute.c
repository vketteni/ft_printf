/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:07:04 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/20 14:14:15 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

unsigned int	ft_absolute(int n)
{
	long abs;

	abs = (long)n;
	if (n < 0)
		return (-abs);
	return (abs);
}