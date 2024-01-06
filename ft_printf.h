/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:45:09 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/06 22:07:44 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

char	*ft_decimal_to_base(unsigned long decimal, int base);

int		ft_base_to_decimal(char *src, int base);

int		ft_print_char(char c);

int		ft_print_str(char *str);

int		ft_print_dec(long dec);

int		ft_print_ptr(void *p);

int		ft_print_hex(unsigned long hex, int uppercase);

#endif