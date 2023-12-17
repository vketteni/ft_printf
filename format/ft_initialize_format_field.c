/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_format_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:33:14 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/17 20:42:00 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

t_format_field *ft_initialize_format_field(void)
{
	t_format_field *field;

	field = (t_format_field *)malloc(sizeof(t_format_field));
	if (field == 0)
		return 0;

	field->min_width = 0;
	field->precision = 0;
	field->specifier = '\0';
	field->flag_left_justify = 0;
	field->flag_zero_padding = 0;
	field->flag_always_sign = 0;
	field->flag_alternative_form = 0;
	field->flag_starts_with_blank = 0;

	return field;
}