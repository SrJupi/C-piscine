/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:50:13 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/10 22:14:13 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	generate_board(char *argv, int size);

int	check_size(char *console_info)
{
	int	counter;

	counter = 0;
	while (*console_info != '\0')
	{
		if (counter == 0 && (*console_info <= '0' || *console_info >= '9'))
			return (counter);
		if (*console_info >= '0' && *console_info <= '9')
			counter++;
		console_info++;
	}
	return (counter);
}

int	check_valid_numbers(char *console_info, int size)
{
	int	max_int_size;

	max_int_size = size / 4;
	while (*console_info != '\0')
	{
		if ((*console_info < '0' || *console_info > max_int_size + '0')
			&& *console_info != 32)
			return (0);
		console_info++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	size;

	if (argc == 2)
	{
		size = check_size (argv[1]);
		if (size % 4 == 0 && size != 0)
		{
			if (check_valid_numbers (argv[1], size) && size == 16)
				generate_board(argv[1], size);
			else
				write(2, "Error\n", 6);
		}
		else
			write (2, "Error\n", 6);
	}
	else
		write (2, "Error\n", 6);
}
