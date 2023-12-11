/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentketteniss <vincentketteniss@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:10:49 by vincentkett       #+#    #+#             */
/*   Updated: 2023/12/11 20:15:48 by vincentkett      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	while (*(str + count))
	{
		ft_print_char(*(str + count));
		count++;
	}
	return (count);
}