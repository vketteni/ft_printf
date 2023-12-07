/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specifer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:02:35 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/07 18:17:21 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

char	ft_get_specifier(char *format)
{
	while (format && !ft_is_format_specifier(*format))
		format++;
	return (*format);
}
