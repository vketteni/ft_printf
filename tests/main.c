/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:34:34 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/21 16:29:19 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// credits for this header:
// https://github.com/Glagan/42-ft_printf/blob/master/main.c
#ifdef IS_FT
# define HEADER "---ft_printf---\n"
# define PRINTF(...) t += ft_printf(__VA_ARGS__);
#else
# define HEADER "---printf---\n"
# define PRINTF(...) t += printf(__VA_ARGS__);
#endif

int	main(void)
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
	PRINTF(" '%x' '%x' '%x' \n", 0, INT_MAX, -INT_MAX)
	PRINTF(" '%x' '%x' '%x' \n", -1, 0, 1)
	PRINTF(" '%x' '%x' '%x' \n", 15, 16, 17)
	PRINTF("--upper case hexadecimal\n")
	PRINTF(" '%X' '%X' '%X' \n", 0, INT_MAX, -INT_MAX)
	PRINTF(" '%X' '%X' '%X' \n", -1, 0, 1)
	PRINTF(" '%X' '%X' '%X' \n", 15, 16, 17)
#ifdef IS_FT
	printf("\n---\nwritten: ^%d\n", t - 3);
	fflush(stdout);
	while (1);
#else
	printf("\n---\nwritten: ^%d\n", t);
#endif
	return (0);
}
