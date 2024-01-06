/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:12:55 by vincentkett       #+#    #+#             */
/*   Updated: 2024/01/06 18:09:59 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static void	ft_putnbr_fd_rek(long n, int fd)
{
	char	ascii;

	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ascii = (n % 10) + '0';
		write(fd, &ascii, 1);
	}
	else
	{
		ascii = n + '0';
		write(fd, &ascii, 1);
	}
}

int	ft_putnbr_fd(long n, int fd)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = (long)n;
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	ft_putnbr_fd_rek(nbr, fd);
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}


int	ft_print_dec(long dec, t_format_field *field)
{
	int	count;

	count = 0;
	if (field->flag_always_sign && dec >= 0)
		count += ft_print_char('+');
	else if(field->flag_starts_with_blank && dec >= 0)
		count += ft_print_char(' ');
	count += ft_putnbr_fd(dec, 1);

	return (count);
}
