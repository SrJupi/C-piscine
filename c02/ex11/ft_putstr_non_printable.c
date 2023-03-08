/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:43:37 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/11 19:33:42 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	div;
	char	mod;

	while (*str != '\0')
	{
		if (*str >= 32)
			write (1, str, 1);
		else
		{
			mod = *str % 16;
			div = *str / 16;
			if (mod < 10)
				mod = mod + '0';
			else
				mod = 'a' + (mod - 10);
			if (div < 10)
				div = div + '0';
			else
				div = 'a' + (div - 10);
			write (1, "\\", 1);
			write (1, &div, 1);
			write (1, &mod, 1);
		}
		str++;
	}
}
