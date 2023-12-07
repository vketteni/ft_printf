/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:37:32 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/07 18:29:39 by vketteni         ###   ########.fr       */
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

char		ft_get_specifier(char *format);

void		ft_get_flags(char *format, t_format_field *field);

void		ft_get_width(char *format, t_format_field *field, va_list args);

void		ft_get_precision(char *format, t_format_field *field, va_list args);

int			ft_check_validity(char *format, t_format_field *field);

int			ft_check_char_format(char *format);

int			ft_check_int_format(char *format);

int			ft_check_str_format(char *format);

int			ft_check_uint_format(char *format);

int			ft_check_hexlc_format(char *format);

int			ft_check_hexuc_format(char *format);

int			ft_check_ptr_format(char *format);

#endif