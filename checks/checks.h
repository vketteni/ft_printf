/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:12:15 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/16 01:47:23 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

// Include any necessary headers here
# include "../format/format.h"

int	ft_check_validity(const char *format, t_format_field *field);

int	ft_check_char_format(const char *format);

int	ft_check_int_format(const char *format);

int	ft_check_str_format(const char *format);

int	ft_check_uint_format(const char *format);

int	ft_check_hex_format(const char *format);

int	ft_check_ptr_format(const char *format);

#endif
