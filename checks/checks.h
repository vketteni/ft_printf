/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:12:15 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/18 18:57:19 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

// Include any necessary headers here
# include "../format/format.h"

const char	*ft_check_format_validity(const char *format);

const char	*ft_check_char_format(const char *format);

const char	*ft_check_int_format(const char *format);

const char	*ft_check_str_format(const char *format);

const char	*ft_check_uint_format(const char *format);

const char	*ft_check_hex_format(const char *format);

const char	*ft_check_ptr_format(const char *format);

#endif
