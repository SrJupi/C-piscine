/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:33:14 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/07 17:45:01 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(int start, char to_print[], int n, int size)
{
	int	i;

	i = start;
	if (n == 0)
	{
		write (1, to_print, size);
		if (to_print[0] != 10 - size + '0')
		{
			write (1, ", ", 2);
		}
		return ;
	}
	while (i <= 9)
	{
		to_print[size - n] = i + '0';
		print_numbers (i + 1, to_print, n - 1, size);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	to_print[9];

	print_numbers(0, to_print, n, n);
}
