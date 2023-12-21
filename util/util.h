/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:57:15 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/20 14:14:15 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "../libft/libft.h"

int		ft_is_format_specifier(char c);

int		ft_is_flag(char c);

char	*ft_tobase(unsigned long decimal, int base);

int		ft_todecimal(char *src, int base);

int		ft_number_length(unsigned long nbr, int base);

unsigned int	ft_absolute(int n);

#endif