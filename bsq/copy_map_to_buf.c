/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map_to_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:40:48 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/20 13:20:48 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	copy_map_to_buf(char *buf, char *map_path, int map_size)
{
	int		f;
	ssize_t	nr_bytes;

	f = open(map_path, O_RDONLY);
	if (f > 0)
	{
		nr_bytes = read(f, buf, map_size);
	}
	else
	{
		write(2, "map error\n", 10);
		return (0);
	}
	close(f);
	return (1);
}
