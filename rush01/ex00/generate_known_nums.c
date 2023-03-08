/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_known_nums.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:59:17 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/10 23:15:30 by adrda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	found_four(int *board, int i, int n);

void	found_one(int *board, int i, int n)
{
	int	helper;

	if (i < n)
	{
		board[i] = n;
	}
	else if (i < n * 2)
	{
		board[i + n * 2] = n;
	}
	else if (i < n * 3)
	{
		helper = i % (n * 2);
		helper = helper * n;
		board[helper] = n;
	}
	else
	{
		helper = i % (n * 3);
		helper = helper * n + 3;
		board[helper] = n;
	}
}

void	found_two_one(int *board, int i, int n)
{
	int	helper;

	if (i < n)
	{
		board[i] = 3;
	}
	else if (i < n * 2)
	{
		board[i + n * 2] = 3;
	}
	else if (i < n * 3)
	{
		helper = i % (n * 2);
		helper = helper * n;
		board[helper] = 3;
	}
	else
	{
		helper = i % (n * 3);
		helper = helper * n + 3;
		board[helper] = 3;
	}
}

void	found_two_three(int *board, int i, int n)
{
	int	helper;

	if (i < n)
	{
		board[i + n] = n;
	}
	else if (i < n * 2)
	{
		board[i + n] = n;
	}
	else if (i < n * 3)
	{
		helper = i % (n * 2);
		helper = helper * n;
		board[helper + 1] = n;
	}
	else
	{
		helper = i % (n * 3);
		helper = helper * n + 3;
		board[helper - 1] = n;
	}
}

void	generate_known_nums(int *board, int *hints, int n)
{
	int	i;

	i = 0;
	while (i < n * n)
	{
		if (hints[i] == 1)
			found_one(board, i, n);
		else if (hints[i] == n)
			found_four(board, i, n);
		else if (hints[i] == 2)
		{
			if (i % (n * 2) < n)
			{
				if (hints[i + n] == 1)
					found_two_one(board, i, n);
				else if (hints[i + n] == 3)
					found_two_three(board, i, n);
			}
			else
			{
				if (hints[i - n] == 1)
					found_two_one(board, i, n);
				else if (hints[i - n] == 3)
					found_two_three(board, i, n);
			}
		}
		i++;
	}
}
