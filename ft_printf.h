/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:45:09 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/16 01:44:14 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "checks/checks.h"
# include "format/format.h"
# include "libft/libft.h"
# include "print/print.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

#endif