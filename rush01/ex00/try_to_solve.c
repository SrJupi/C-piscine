/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:18:16 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/10 21:16:45 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check_line(int *board, int *possible_num, int i)
{
	int	counter;
	int	tmp;

	i = i / 4;
	counter = 0;
	while (counter < 4)
	{
		if (board[i * 4 + counter] != 0)
		{
			tmp = board[i * 4 + counter];
			possible_num[tmp - 1] = 0;
		}
		counter++;
	}
}

void	check_column(int *board, int *possible_num, int i)
{
	int	counter;
	int	tmp;

	i = i % 4;
	counter = 0;
	while (counter < 4)
	{
		if (board[i + counter * 4] != 0)
		{
			tmp = board[i + counter * 4];
			possible_num[tmp - 1] = 0;
		}
		counter++;
	}
}

int	check_possibles_nums(int *board, int *possible_num, int position)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (i++ < 4)
		if (possible_num[i] > 0)
			counter++;
	if (counter == 1)
	{
		i = 0;
		while (i < 4)
		{
			if (possible_num[i] != 0)
				board[position] = i + 1;
			i++;
		}
		return (1);
	}
	else
		return (0);
}

void	try_to_solve(int *board)
{
	int	was_number_inserted;
	int	i;
	int	j;
	int	possible_num [4];

	was_number_inserted = 1;
	while (was_number_inserted == 1)
	{
		was_number_inserted = 0;
		i = -1;
		while (i++ < 16)
		{
			if (board[i] == 0)
			{
				j = -1;
				while (j++ < 3)
					possible_num [j] = 1;
				check_line(board, possible_num, i);
				check_column(board, possible_num, i);
				if (check_possibles_nums(board, possible_num, i) == 1)
					was_number_inserted = 1;
			}
		}
	}
}
