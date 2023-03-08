/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:07:25 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/10 23:18:42 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	generate_known_nums(int *board, int *hints, int n);
void	try_to_solve(int *board);
void	print_nums(int *board);

void	populate_hints(char *argv, int *hints)
{
	int	i;

	i = 0;
	while (*argv != '\0')
	{
		if (*argv >= '0' && *argv <= '9')
		{
			hints[i] = *argv - '0';
			i++;
		}
		argv++;
	}
}

void	populate_array(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		nums[i] = 0;
		i++;
	}
}

void	generate_board(char *argv, int size)
{
	int		*nums;
	int		*hints;

	nums = (int *)malloc(sizeof(int) * size);
	hints = (int *)malloc(sizeof(int) * size);
	populate_hints(argv, hints);
	populate_array(nums, size);
	generate_known_nums(nums, hints, size / 4);
	try_to_solve(nums);
	print_nums(nums);
	free(nums);
	free(hints);
}
