/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:26:08 by vketteni          #+#    #+#             */
/*   Updated: 2023/12/22 01:40:08 by vketteni         ###   ########.fr       */
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
