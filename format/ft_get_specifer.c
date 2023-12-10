/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specifer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:02:35 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/10 01:54:29 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

t_format_field	*ft_get_specifier(char *format, t_format_field *field)
{
	while (format && !ft_is_format_specifier(*format))
		format++;
	if (ft_is_format_specifier(*format))
		field->specifier = *format;
	return (field);
}
