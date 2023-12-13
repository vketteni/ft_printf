/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:34:34 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/13 20:57:06 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test_single_flag(char *format, void *arg)
{
	int				d;
	unsigned int	u;
	char			*s;
    char            c;
	void			*p;
	long long int	x;
	long long int	X;

	if (format != NULL)
	{
		if (format[1] == 'd' )
		{
			d = *((int *)arg);
			ft_printf("Received integer: %d\n", d);
		}
		else if (format[1] == 'u' )
		{
			u = *((unsigned int *)arg);
			ft_printf("Received unsigned integer: %u\n", u);
		}
		else if (format[1] == 'c')
		{
			c = *((char *)arg);
			ft_printf("Received char: %c\n", c);
		}
		else if (format[1] == 's')
		{
			s = (char *)arg;
			ft_printf("Received string: %s\n", s);
		}
		else if (format[1] == 'p')
		{
			p = (void *)arg;
			ft_printf("Received pointer: %p\n", p);
		}
		else if (format[1] == 'x')
		{
			x = *(long long int *)arg;
			ft_printf("Received lowercase hex: %x\n", x);
		}
		else if (format[1] == 'X')
		{
			X = *(long long int *)arg;
			ft_printf("Received uppercase hex: %X\n", X);
		}
		else
		{
			ft_printf("Unsupported format\n");
		}
	}
	else
	{
		ft_printf("Invalid format\n");
	}
}

int	main(void)
{
	int				d;
	unsigned int	u;
	char			*s;
    char            c;
	void			*p;
	unsigned int	x;
	unsigned int	X;

	c = 'c';
	d = 42;
	s = "world";
	u = (unsigned int)d;
	p = &c;
	x = (unsigned int)d;
	X = x;

	// printf("'%010x'\n", x);
	// printf("%p\n", p);
	// test_single_flag("%c\n", &c);
    // test_single_flag("%d\n", &d);
    // test_single_flag("%u\n", &u);
    // test_single_flag("%s\n", s);
    // test_single_flag("%p\n", p);
    // test_single_flag("%x\n", &x);
    // test_single_flag("%X\n", &X);
	return (0);
}

// cc main.c format/*c checks/*.c print/*.c util/*.c libft/*.c ft_printf.c 

	// int		min_width;
	// int		precision;
	// char	specifier;
	// int		flag_left_justify;
	// int		flag_zero_padding;
	// int		flag_always_sign;
	// int		flag_alternative_form;
	// int		flag_starts_with_blank;