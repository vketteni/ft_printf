/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:50:22 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/11 20:08:21 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "../ft_printf.h"

int	ft_print_char(char c);

int	ft_print_str(char *str);

int	ft_print_int(int num);

int	ft_print_ptr(void *p);

int	ft_print_hex_lc(unsigned int d);

int	ft_print_hex_uc(unsigned int d);

int	ft_print_int_unsigned(unsigned int d);

int	ft_print_format(const char *format, t_format_field *field, va_list args);

int	ft_print_char(char c);

#endif
