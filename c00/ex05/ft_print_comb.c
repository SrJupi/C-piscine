/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:45:37 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/05 19:46:58 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writenumbers(char c, char d, char u)
{
	if (c == 55)
	{
		write(1, &c, 1);
		write(1, &d, 1);
		write(1, &u, 1);
	}
	else
	{
		write(1, &c, 1);
		write(1, &d, 1);
		write(1, &u, 1);
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	char	c;
	char	d;
	char	u;

	c = 48;
	while (c <= 57)
	{
		d = 48;
		while (d <= 57)
		{
			u = 48;
			while (u <= 57)
			{
				if (c < d && d < u)
				{
					writenumbers (c, d, u);
				}
				u++;
			}
		d++;
		}
	c++;
	}
}
