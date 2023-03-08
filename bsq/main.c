/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:05:22 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/20 14:35:20 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	solve_map(char *map_path);

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		write(1, "error\n", 6);
	else
	{
		while (i < argc)
		{
			solve_map(argv[i]);
			if (i != argc - 1)
				write (1, "\n", 1);
			i++;
		}
	}
	return (0);
}
