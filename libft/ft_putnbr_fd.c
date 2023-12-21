/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:26:08 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/20 15:31:05 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_putnbr_fd(long n, int fd)
{
	long	nbr;

	nbr = (long)n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	ft_putnbr_fd_rek(nbr, fd);
}
