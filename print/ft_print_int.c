/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:12:55 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/11 20:15:32 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_int(int num)
{
	int	count;

	ft_putnbr_fd(num, 1);
	count = 0;
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}