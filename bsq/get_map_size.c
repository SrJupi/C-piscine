/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:31:54 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/20 14:33:46 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	get_map_size(char *map_path)
{
	int		i;
	int		f;
	ssize_t	nr_bytes;
	char	buf[1];

	i = 0;
	f = open(map_path, O_RDONLY);
	if (f > 0)
	{
		nr_bytes = 1;
		while (nr_bytes != 0)
		{
			i++;
			nr_bytes = read(f, buf, 1);
		}
		close(f);
	}
	return (i);
}
