/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:34:34 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/17 16:03:21 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char			c = 'c';
	int				d = 42;
	char			*s = "world";
	unsigned int	u = (unsigned int)d;
	void			*p = &c;
	unsigned int	x = (unsigned int)d;
	unsigned int	X = x;

	char format[] = " '%c' '%c' '%c' \n";
	printf("printf return value:\t'%5d'\n"
	, printf(format, '2', '1', 0));
	printf("===============\n");
	ft_printf("ft_printf return value:\t'%5d'\n"
	, ft_printf(format, '2', '1', 0));

	return (0);
}

// cc -g main.c format/*c checks/*.c print/*.c util/*.c libft/*.c ft_printf.c
// /opt/homebrew/bin/gcc-13 -fdiagnostics-color=always -g /Users/vincentketteniss/42berlin/ft_printf/main.c format/*c checks/*.c print/*.c util/*.c libft/*.c /Users/vincentketteniss/42berlin/ft_printf/ft_printf.c -o /Users/vincentketteniss/42berlin/ft_printf/main