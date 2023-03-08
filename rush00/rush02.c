/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleserra <aleserra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:02:03 by aleserra          #+#    #+#             */
/*   Updated: 2022/04/03 20:24:08 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	isvalidnumber2(int columna, int fila)
{
	if (columna <= 0 || fila <= 0)
	{
		write (2, "Insert a positive number!\n", 26);
		return (0);
	}
	else
	{
		return (1);
	}
}

void	write_line2(char characters[3], int numcolumnas)
{
	int	columna_actual;

	columna_actual = 1;
	while (columna_actual <= numcolumnas)
	{
		if (columna_actual == 1)
		{
			ft_putchar(characters[0]);
		}
		else if (columna_actual < numcolumnas)
		{
			ft_putchar(characters[1]);
		}
		else
		{
			ft_putchar(characters[2]);
		}
		columna_actual++;
	}
	ft_putchar('\n');
}

void	rush02(int x, int y)
{
	int	linea_actual;

	linea_actual = 1;
	if (isvalidnumber2(x, y))
	{
		while (linea_actual <= y)
		{
			if (linea_actual == 1)
			{
				write_line2("ABA", x);
			}
			else if (linea_actual < y)
			{
				write_line2("B B", x);
			}
			else
			{
				write_line2("CBC", x);
			}
			linea_actual++;
		}
	}
}
