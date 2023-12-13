/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:50:22 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/13 06:05:52 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "../ft_printf.h"
# include "../format/format.h"

int	ft_print_char(char c);

int	ft_print_str(char *str);

int	ft_print_int(int num);

int	ft_print_ptr(void *p);

int ft_print_hex(long long int hexa, int uppercase);

int	ft_print_int_unsigned(unsigned int d);

int	ft_print_format(t_format_field *field, va_list args);

int	ft_print_char(char c);

#endif
