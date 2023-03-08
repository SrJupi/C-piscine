/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:55:51 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/21 19:45:13 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	write (1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) != '\0'
		|| *(s2 + i) != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (0);
}

void	ft_sort_int_tab(char **tab, int size)
{
	char	*tmp;
	int		idx;
	int		idx2;

	idx = 1;
	while (idx < size - 1)
	{
		idx2 = idx + 1;
		tmp = tab[idx];
		while (idx2 < size)
		{
			if (ft_strcmp(tmp, tab[idx2]) > 0)
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

int	main(int argc, char **argv)
{
	int	i;

	ft_sort_int_tab(argv, argc);
	i = 1;
	while (i < argc)
	{
		print_str(argv[i]);
		i++;
	}
}
