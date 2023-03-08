/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:49:50 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/18 13:44:04 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num_to_char(int nb)
{
	char	num_to_char [10];
	int		tmp;
	int		i;

	i = 0;
	while (nb > 0)
	{
		tmp = nb % 10;
		num_to_char [i] = tmp + '0';
		i++;
		nb /= 10;
	}
	while (i > 0)
	{
		write (1, &num_to_char[i - 1], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
			write(1, "2147483648", 10);
		else
			print_num_to_char(nb * -1);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	else
	{
		print_num_to_char(nb);
	}
}
