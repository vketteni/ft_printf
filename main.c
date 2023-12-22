/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:13:30 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/22 13:47:12 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf(" '%d' \n",
	ft_printf(" '%05u' \n", 123));

	return (0);
}
// cc -g format/*.c print/*.c checks/*.c util/*.c libft/*.c main.c ft_printf.c -o ft_printf