/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:37:32 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/10 01:57:32 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include "../ft_printf.h"
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

int			ft_check_validity(const char *format, t_format_field *field);

int			ft_check_char_format(const char *format);

int			ft_check_int_format(const char *format);

int			ft_check_str_format(const char *format);

int			ft_check_uint_format(const char *format);

int			ft_check_hexlc_format(const char *format);

int			ft_check_hexuc_format(const char *format);

int			ft_check_ptr_format(const char *format);

#endif