/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:46:33 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/08 13:57:00 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	tmp;
	int	idx;
	int	idx2;

	idx = 0;
	while (idx < size - 1)
	{
		idx2 = idx + 1;
		tmp = tab[idx];
		while (idx2 < size)
		{
			if (tab[idx2] < tmp)
			{
				tab[idx] = tab[idx2];
				tab[idx2] = tmp;
				tmp = tab[idx];
			}
			idx2++;
		}
		idx++;
	}
}
