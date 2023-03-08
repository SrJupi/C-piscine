/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_not_cry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:04:47 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/20 22:06:04 by lsulzbac         ###   ########.fr       */
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

void	fill_mock(char **qtd_map, t_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->ln)
	{
		j = 0;
		while (j < map_info->len)
		{
			qtd_map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	find_squares(char **qtd_map, char **map, t_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->ln)
	{
		j = 0;
		while (j < map_info->len)
		{
			if (map[i][j] == map_info->e_c)
			{
				qtd_map[i][j]++;
			}
			j++;
		}
		i++;
	}
}

void	try_not_cry(char **map, t_info *map_info)
{
	char	**qtd_map;
	int		i;

	i = 0;
	(void)map;
	qtd_map = (char **) malloc (sizeof(char *) * map_info->ln);
	if (qtd_map == NULL)
		return ;
	else
	{
		while (i < map_info->ln)
		{
			qtd_map[i] = (char *) malloc (sizeof(char) * map_info->len);
			if (qtd_map[i] == NULL)
				return ;
			i++;
		}
	}
	fill_mock(qtd_map, map_info);
	find_squares(qtd_map, map, map_info);
}
