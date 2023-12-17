/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:11:12 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/16 02:10:19 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_ptr(void *p)
{
	long long int	ptr;

	ptr = (long long int)p;
	return (ft_print_hex(ptr, 0));
}
