/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:13:52 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/13 06:07:38 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int ft_puthex_fd(unsigned int hex, int uppercase, int fd)
{
    int     case_constant;

    if (uppercase)
        case_constant = 'a' - 'A';
    else
        case_constant = 0;
    if (hex < 10)
    {
        ft_putchar_fd(hex + '0', fd);
        return (1);
    }
    else
    {
        ft_putchar_fd(hex - 10 + 'a' - case_constant, fd);
        return (1);
    }
}

static int ft_print_hex_rekursion(long long int hexa, int uppercase)
{
    int count = 0;
    if (hexa > 15)
    {
        count += ft_print_hex_rekursion(hexa / 16, uppercase);
        count += ft_puthex_fd(hexa % 16, uppercase, 1);
    }
    else
        count += ft_puthex_fd(hexa, uppercase, 1);
    return count;
}

int ft_print_hex(long long int hexa, int uppercase)
{
    int count = 0;
    count += ft_print_char('0');
    if (!uppercase)
        count += ft_print_char('x');
    else 
        count += ft_print_char('X');
    
    count += ft_print_hex_rekursion(hexa, uppercase);
    return count;
}



