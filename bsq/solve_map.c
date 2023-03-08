/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:24:19 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/20 13:21:28 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		get_map_size(char *map_path);
int		copy_map_to_buf(char *buf, char *map_path, int map_size);
void	check_map(char *buf);

void	solve_map(char *map_path)
{
	int		map_size;
	char	*buf;

	map_size = get_map_size(map_path);
	if (map_size > 0)
	{
		buf = (char *) malloc (sizeof(char) * map_size);
		if (buf == NULL)
			write (2, "map error\n", 10);
		else
		{
			if (copy_map_to_buf(buf, map_path, map_size))
				check_map(buf);
		}
		free(buf);
	}
	else
		write (2, "map error\n", 10);
}
