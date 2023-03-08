/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:01:30 by mpuig-ma          #+#    #+#             */
/*   Updated: 2022/04/03 20:23:24 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	isvalidnumber1(int columna, int fila)
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

void	write_line1(char characters[3], int numcolumnas)
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

void	rush01(int x, int y)
{
	int	linea_actual;

	linea_actual = 1;
	if (isvalidnumber1(x, y))
	{
		while (linea_actual <= y)
		{
			if (linea_actual == 1)
			{
				write_line1("/*\\", x);
			}
			else if (linea_actual < y)
			{
				write_line1("* *", x);
			}
			else
			{
				write_line1("\\*/", x);
			}
			linea_actual++;
		}
	}
}
