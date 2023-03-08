/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:48:00 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/05 19:49:08 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	num_to_char(int number)
{
	char	to_print[2];
	int		tmp;
	int		i;

	to_print[0] = '0';
	to_print[1] = '0';
	i = 1;
	while (number > 0)
	{
		tmp = number % 10;
		to_print[i] = tmp + '0';
		i--;
		number /= 10;
	}
	write (1, to_print, 2);
}

void	comma_or_newline(int first_number)
{
	if (first_number != 98)
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	first_number;
	int	second_number;

	first_number = 0;
	while (first_number <= 99)
	{
		second_number = first_number + 1;
		while (second_number <= 99)
		{
			if (first_number < second_number)
			{
				num_to_char(first_number);
				write (1, " ", 1);
				num_to_char(second_number);
				comma_or_newline(first_number);
			}
			second_number++;
		}
		first_number++;
	}
}
