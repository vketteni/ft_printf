/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:34:34 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/22 14:48:16 by vketteni         ###   ########.fr       */
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

#define PTR_CAST (void *)(uintptr_t)

int	main(void)
{
	int	t;
	int	header_count;

	header_count = 0;
	t = 0;
	PRINTF(HEADER) header_count++;


	PRINTF("--basic\n")
	PRINTF("This is a simple test.")
	PRINTF("This is a simple test.\nSecond sentence.\n")
	PRINTF("")
	PRINTF("\n")


	PRINTF("--specifier --without --flags")
	
	PRINTF("--integer (%%d)\n")
	PRINTF(" '%d' '%d' '%d' \n", INT_MAX, -INT_MAX, 0)
	PRINTF(" '%d' '%d' '%d' \n", -1, 0, 1)
	PRINTF(" '%d' '%d' '%d' \n", INT_MIN, 100, -100)
	PRINTF(" '%d' '%d' '%d' \n", 12345, -12345, 2147483647)
	PRINTF(" '%d' '%d' '%d' \n", 2147483647 - 1, 0, 42)

	PRINTF("--integer (%%i)\n")
	PRINTF(" '%i' '%i' '%i' \n", INT_MAX, -INT_MAX, 0)
	PRINTF(" '%i' '%i' '%i' \n", -1, 0, 1)
	PRINTF(" '%i' '%i' '%i' \n", INT_MIN, 100, -100)
	PRINTF(" '%i' '%i' '%i' \n", 12345, -12345, 2147483647)
	PRINTF(" '%i' '%i' '%i' \n", 2147483647 - 1, 0, 42)

	PRINTF("--unsigned integer (%%u)\n")
	PRINTF(" '%u' '%u' '%u' \n", UINT_MAX, 0, 1)
	PRINTF(" '%u' '%u' '%u' \n", 12345, 67890, 4294967295U)
		// UINT_MAX for 32-bit systems
	PRINTF(" '%u' '%u' '%u' \n", 100, 200, 300)
	PRINTF(" '%u' '%u' '%u' \n", 500, 1000, 1500)

	PRINTF("--character (%%c)\n")
	PRINTF(" '%c' '%c' '%c' \n", 'A', 'z', '0')
	PRINTF(" '%c' '%c' '%c' \n", '!', '@', '#')
	PRINTF(" '%c' '%c' '%c' \n", 32, 127, 255) // Testing space, delete,
		// and extended ASCII
	PRINTF(" '%c' '%c' '%c' \n", '\n', '\t', '\\')
	PRINTF(" '%c' '%c' '%c' \n", '%', '_', '+')

	PRINTF("--string (%%s)\n")
	PRINTF(" '%s' \n", "A simple string")
	PRINTF(" '%s' \n", "") // Empty string
	PRINTF(" '%s' \n", "String with special characters !@#$%^&*()")
	PRINTF(" '%s' \n", "String with a newline character\nin the middle")
	PRINTF(" '%s' \n",
			"Long string: Lorem ipsum dolor sit amet,"
			"consectetur adipiscing elit, sed do eiusmod tempor "
			"incididunt ut labore et dolore magna aliqua.")

	PRINTF("--pointer (%%p)\n")
	PRINTF(" '%p' '%p' '%p' \n", (void *)0x0, PTR_CAST 1, PTR_CAST INT_MAX)

	PRINTF("--lower case hexadecimal (%%x)\n")
	PRINTF(" '%x' '%x' '%x' \n", INT_MAX, -INT_MAX, 0)
	PRINTF(" '%x' '%x' '%x' \n", -1, 0, 1)
	PRINTF(" '%x' '%x' '%x' \n", 15, 16, 17)

	PRINTF("--upper case hexadecimal (%%X)\n")
	PRINTF(" '%X' '%X' '%X' \n", INT_MAX, -INT_MAX, 0)
	PRINTF(" '%X' '%X' '%X' \n", -1, 0, 1)
	PRINTF(" '%X' '%X' '%X' \n", 15, 16, 17)
	PRINTF(" '%%s' \n")


	PRINTF("--specifier --with --flags\n")

    PRINTF("--integer %%d with flags %s\n", HEADER) header_count++;
    PRINTF("Space: '% d' '% d' \n", 123, -123)
    PRINTF("Minus: '%-d' '%-d' \n", 123, -123)
    PRINTF("Zero: '%0d' '%0d' \n", 123, -123)
    PRINTF("Plus: '%+d' '%+d' '%+d' \n", 123, -123, 0)
    PRINTF("Space + Minus: '% -d' '% -d' \n", 123, -123)
    PRINTF("Space + Zero: '% 0d' '% 0d' \n", 123, -123)
    //PRINTF("Space + Plus: '% +d' '% +d' \n", 123, -123)
    PRINTF("Minus + Plus: '%-+d' '%-+d' \n", 123, -123)
	PRINTF(" '% d' '% i' '%u' \n", 42, 42, 42)

    PRINTF("--integer %%i with flags %s\n", HEADER) header_count++;
    PRINTF(" '% i' '% i' \n", 123, -123) // Space
    PRINTF(" '%-i' '%-i' \n", 123, -123) // Minus
    PRINTF(" '%0i' '%0i' \n", 123, -123) // Zero
    PRINTF(" '%+i' '%+i' \n", 123, -123) // Plus
    PRINTF(" '% -i' '% -i' \n", 123, -123) // Space + Minus
    PRINTF(" '% 0i' '% 0i' \n", 123, -123) // Space + Zero
    //PRINTF(" '% +i' '% +i' \n", 123, -123) // Space + Plus
    PRINTF(" '%-+i' '%-+i' \n", 123, -123) // Minus + Plus

    PRINTF("--unsigned integer %%u with flags %s\n", HEADER) header_count++;
    //PRINTF(" '% u' \n", 123)  // Space
    PRINTF(" '%-5u' \n", 123)  // Minus
    PRINTF(" '%05u' \n", 123)  // Zero
    //PRINTF(" '% -u' \n", 123) // Space + Minus
    //PRINTF(" '% 0u' \n", 123) // Space + Zero
    //PRINTF(" '%-0u' \n", 123) // Minus + Zero (though '0' is ignored when '-' is present)

    PRINTF("--character %%c with flags %s\n", HEADER) header_count++;
    PRINTF(" '%c' \n", 'A') // Without flag
    PRINTF(" '%-c' \n", 'A') // With Minus flag

    PRINTF("--string %%s with flags %s\n", HEADER) header_count++;
    PRINTF(" '%s' \n", "Test String")  // Without flag
    PRINTF(" '%-s' \n", "Test String") // With Minus flag

    void *ptr = (void*)0x12345678;
    PRINTF("--pointer %%p with flags %s\n", HEADER) header_count++;
    PRINTF(" '%p' \n", ptr)  // Without flag
    PRINTF(" '%-p' \n", ptr) // With Minus flag

    PRINTF("--hexadecimal lower case %%x with flags %s\n", HEADER) header_count++;
    PRINTF(" '%x' \n", 0x123ABC)  // Without flag
    PRINTF(" '%-x' \n", 0x123ABC) // Minus
    PRINTF(" '%0x' \n", 0x123ABC) // Zero
    PRINTF(" '%#x' \n", 0x123ABC) // Hash
    PRINTF(" '%-#x' \n", 0x123ABC) // Minus + Hash
    PRINTF(" '%0#x' \n", 0x123ABC) // Zero + Hash (though '0' is ignored when '-' is present)

    PRINTF("--hexadecimal upper case %%X with flags %s\n", HEADER) header_count++;
    PRINTF(" '%X' \n", 0x123ABC)  // Without flag
    PRINTF(" '%-X' \n", 0x123ABC) // Minus
    PRINTF(" '%0X' \n", 0x123ABC) // Zero
    PRINTF(" '%#X' \n", 0x123ABC) // Hash
    PRINTF(" '%-#X' \n", 0x123ABC) // Minus + Hash
    PRINTF(" '%0#X' \n", 0x123ABC) // Zero + Hash (though '0' is ignored when '-' is present)


#ifdef IS_FT
	printf("\n---\nwritten: ^%d\n", t - (header_count * 3));
	fflush(stdout);
	while (1);
#else
	printf("\n---\nwritten: ^%d\n", t);
	while (header_count--);
#endif
	return (0);
}
