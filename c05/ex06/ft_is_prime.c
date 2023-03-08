/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:15:33 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/21 14:20:16 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	is_prime;

	i = 2;
	is_prime = 1;
	while (i < nb && is_prime)
	{
		if (nb % i == 0)
			is_prime = 0;
		i++;
	}
	if (nb <= 1)
		is_prime = 0;
	return (is_prime);
}
