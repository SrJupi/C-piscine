/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrda-si <adrda-si@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:40:51 by adrda-si          #+#    #+#             */
/*   Updated: 2022/04/10 23:15:33 by adrda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	found_four_1(int *board, int i, int n)
{
	board[i] = 1;
	board[i + n] = 2;
	board[i + n * 2] = 3;
	board[i + n * 3] = n;
}

void	found_four_2(int *board, int i,	int n)
{
	board[i + n * 2] = 1;
	board[i + n] = 2;
	board[i] = 3;
	board[i - n] = n;
}

void	found_four_3(int *board, int i, int n)
{
	int	helper;

	helper = i % (n * 2);
	helper = helper * n;
	board[helper] = 1;
	board[helper + 1] = 2;
	board[helper + 2] = 3;
	board[helper + 3] = n;
}

void	found_four_4(int *board, int i, int n)
{
	int	helper;

	helper = i % (n * 3);
	helper = helper * n + 3;
	board[helper] = 1;
	board[helper - 1] = 2;
	board[helper - 2] = 3;
	board[helper - 3] = n;
}

void	found_four(int *board, int i, int n)
{
	if (i < n)
	{
		found_four_1(board, i, n);
	}
	else if (i < n * 2)
	{
		found_four_2(board, i, n);
	}
	else if (i < n * 3)
	{
		found_four_3(board, i, n);
	}
	else
	{
		found_four_4(board, i, n);
	}
}
