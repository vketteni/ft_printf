/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:34:34 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/21 14:53:16 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <strings.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#ifdef IS_FT
    #define HEADER         "---ft_printf---\n"
    #define PRINTF(...)  t += ft_printf(__VA_ARGS__);
#else
    #define HEADER         "---printf---\n"
    #define PRINTF(...)  t += printf(__VA_ARGS__);
#endif

int main(void)
{
	int	t;

	t = 0;
	PRINTF(HEADER)

	PRINTF("--basic\n")
    PRINTF("This is a simple test.")
    PRINTF("This is a simple test.\nSecond sentence.\n")
    PRINTF("")
    PRINTF("\n")

	PRINTF("--lower case hexadecimal\n")
	PRINTF(" '%x' '%x' '%x' ", 0, INT_MAX, -INT_MAX)


	#ifdef IS_FT
		printf("\n---\nwritten: ^%d\n", t - 3);
		fflush(stdout);
		while (1);
	# else
		printf("\n---\nwritten: ^%d\n", t);
	#endif
	return (0);
}


// int	main(void)
// {
// 	char			c = 'c';
// 	int				d = 42;
// 	char			*s = "world";
// 	unsigned int	u = (unsigned int)d;
// 	void			*p = &c;
// 	unsigned int	x = (unsigned int)d;
// 	unsigned int	X = x;

// 	//char format[] = " '%c' '%c' '%c' \n";
// 	char format[] = " '%x' '%x' \n";
// 	printf("printf return value:\t'%5d'\n"
// 	, printf(format, 0, -0));
// 	printf("===============\n");
// 	ft_printf("ft_printf return value:\t'%5d'\n"
// 	, ft_printf(format, 0, -0));


// 	return (0);
// }

// cc -g main.c format/*c checks/*.c print/*.c util/*.c libft/*.c ft_printf.c

	// TEST(1, print(" %d ", 0));
	// TEST(2, print(" %d ", -1));
	// TEST(3, print(" %d ", 1));
	// TEST(4, print(" %d ", 9));
	// TEST(5, print(" %d ", 10));
	// TEST(6, print(" %d ", 11));
	// TEST(7, print(" %d ", 15));
	// TEST(8, print(" %d ", 16));
	// TEST(9, print(" %d ", 17));
	// TEST(10, print(" %d ", 99));
	// TEST(11, print(" %d ", 100));
	// TEST(12, print(" %d ", 101));
	// TEST(13, print(" %d ", -9));
	// TEST(14, print(" %d ", -10));
	// TEST(15, print(" %d ", -11));
	// TEST(16, print(" %d ", -14));
	// TEST(17, print(" %d ", -15));
	// TEST(18, print(" %d ", -16));
	// TEST(19, print(" %d ", -99));
	// TEST(20, print(" %d ", -100));
	// TEST(21, print(" %d ", -101));
	// TEST(22, print(" %d ", INT_MAX));
	// TEST(23, print(" %d ", INT_MIN));
	// TEST(24, print(" %d ", LONG_MAX));
	// TEST(25, print(" %d ", LONG_MIN));
	// TEST(26, print(" %d ", UINT_MAX));
	// TEST(27, print(" %d ", ULONG_MAX));
	// TEST(28, print(" %d ", 9223372036854775807LL));
	// TEST(29, print(" %d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));