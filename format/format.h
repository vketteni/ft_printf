/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:37:32 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/12 21:58:23 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include <stdarg.h>
# include "../libft/libft.h"
# include "../util/util.h"

typedef struct s_format_field
{
	int		width;
	int		precision;
	char	specifier;
	int		flag_left_justify;
	int		flag_zero_padding;
	int		flag_always_sign;
	int		flag_alternative_form;
	int		flag_starts_with_blank;
}			t_format_field;

t_format_field	*ft_get_specifier(const char *format, t_format_field *field);

t_format_field	*ft_get_flags(const char *format, t_format_field *field);

t_format_field	*ft_get_width(const char *format, t_format_field *field, va_list args);

t_format_field	*ft_get_precision(const char *format, t_format_field *field, va_list args);

#endif