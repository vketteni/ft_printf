/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:11:12 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/12 00:13:19 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_print_ptr(void *p)
{
    long long int   ptr;

    ptr = (long long int)p;

}

static void ft_print_hex(long long int hexa, int uc, int fd)
{
    ft_print_char('0');
    if (uc)
        ft_print_char('x');
    else 
        ft_print_char('X');
    
    ft_print_hex_rekursion(hexa, false, 1);
}

static void ft_print_hex_rekursion(long long int hexa, int uc, int fd)
{
    if (hexa > 15)
    {
        ft_print_hex_rekursion(hexa / 16, uc, fd);
        
    }
    else
    {

    }
}