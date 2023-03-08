/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:09:12 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/21 14:13:18 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	while (nb > 0)
	{
		nb -= i;
		i += 2;
		counter++;
	}
	if (nb != 0)
		return (0);
	else
		return (counter);
}
