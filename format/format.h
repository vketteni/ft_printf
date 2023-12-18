/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:37:32 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/18 19:12:04 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include "../libft/libft.h"
# include "../util/util.h"
# include <stdarg.h>

typedef struct s_format_field
{
	int			min_width;
	int			precision;
	char		specifier;
	int			flag_left_justify;
	int			flag_zero_padding;
	int			flag_always_sign;
	int			flag_alternative_form;
	int			flag_starts_with_blank;
}				t_format_field;

t_format_field	*ft_get_specifier(const char *format, t_format_field *field);

t_format_field	*ft_get_flags(const char *format, t_format_field *field);

t_format_field	*ft_get_min_width(const char *format, t_format_field *field,
					va_list *args);

t_format_field	*ft_get_precision(const char *format, t_format_field *field,
					va_list *args);

t_format_field	*ft_initialize_format_field(void);

t_format_field	*ft_get_format_field_attributes(const char *format,
		t_format_field *field, va_list *args);

#endif