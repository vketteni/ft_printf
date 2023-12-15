/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:50:22 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/15 12:13:48 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "../ft_printf.h"
# include "../format/format.h"

int	ft_print_char(char c);

int	ft_print_str(char *str);

int	ft_print_int(int num, int flag_always_sign);

int	ft_print_ptr(void *p);

int ft_print_hex(long long int hexa, int flag_alternative_form);

int	ft_print_int_unsigned(unsigned int d);

int	ft_print_format(t_format_field *field, va_list args);

int	ft_print_padding(t_format_field *field, va_list args);

#endif
