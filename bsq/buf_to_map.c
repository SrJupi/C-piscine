/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_to_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:31:33 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/20 20:05:28 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

typedef struct info_line {
	int		ln;
	int		len;
	char	e_c;
	char	o_c;
	char	f_c;
}	t_info;

void	try_not_cry(char **map, t_info *map_info);

void	get_first_line(char *buf, int *ptr_i)
{
	while (*(buf + *ptr_i) != '\n')
		*ptr_i = *ptr_i + 1;
}

void	base_map(char **map, char *buf)
{
	int	i;
	int	j;
	int	num_lin;

	i = 0;
	get_first_line(buf, &i);
	num_lin = 0;
	while (*(buf + i) != '\0')
	{
		if (*(buf + i) == '\n')
		{
			num_lin++;
			i++;
		}
		j = 0;
		while (*(buf + i) != '\n' && *(buf + i) != '\0')
		{
			map[num_lin - 1][j] = *(buf + i);
			j++;
			i++;
		}
	}
}

void	print_map(char **map, t_info *m_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < m_info->ln)
	{
		j = 0;
		while (j < m_info->len)
		{
			write (1, &map[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

void	buf_to_map(char *buf, t_info *map_info)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **) malloc (sizeof(char *) * map_info->ln);
	if (map == NULL)
		return ;
	else
	{
		while (i < map_info->ln)
		{
			map[i] = (char *) malloc (sizeof(char) * map_info->len);
			if (map[i] == NULL)
				return ;
			i++;
		}
	}
	base_map(map, buf);
	try_not_cry(map, map_info);
	print_map(map, map_info);
	free(map);
}
