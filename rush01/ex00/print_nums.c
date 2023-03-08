/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:19:53 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/10 23:26:22 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nums(int *board)
{
	int		i;
	char	tmp;
	
	i = 0;
	while (i < 16)
	{
		if (i != 0 && i % 4 == 0)
			write (1, "\n", 1);
		tmp = board[i] + '0';
		write (1, &tmp, 1);
		if (i % 4 != 3)
			write (1, " ", 1);
		i++;
	}
	write (1, "\n", 1);
}
