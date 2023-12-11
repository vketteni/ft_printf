/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:34:34 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/11 02:32:06 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	test_single_flag(char *format, void *arg)
{
	int				d;
	unsigned int	ud;
	char			*s;
    char            c;

	if (format != NULL)
	{
		if (format[1] == 'd' )
		{
			d = *((int *)arg);
			ft_printf("Received integer: %d\n", d);
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
	char	c;
	char	*s;
	int		d;
	void	*p;

	p = &c;
	c = 'c';
	s = "world";
	d = 42;

	printf("%ld\n", (long)p);
	printf("%p\n", p);
	// test_single_flag("%c\n", &c);
    // test_single_flag("%d\n", &d);
    // test_single_flag("%s\n", s);
	return (0);
}
