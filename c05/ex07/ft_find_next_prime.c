/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:43:03 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/21 17:54:09 by lsulzbac         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 1;
	while (i)
	{
		if (ft_is_prime(nb))
			i = 0;
		else
			nb++;
	}
	return (nb);
}
