/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:05:04 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/20 19:25:34 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

typedef struct info_line {
	int		ln;
	int		len;
	char	e_c;
	char	o_c;
	char	f_c;
}	t_info;

int		get_info(char *buf, int i, t_info *r_info);
void	get_line_size(char *buf, int i, t_info *r_info);
void	buf_to_map(char *buf, t_info *map_info);

void	check_map(char *buf)
{
	int			i;
	t_info		map_info;

	i = 0;
	while (*(buf + i) != '\0')
	{
		if (*(buf + i) == '\n')
		{
			if (get_info(buf, i, &map_info))
			{
				get_line_size(buf, i, &map_info);
				return ;
			}
			else
			{
				write (2, "map error\n", 10);
				return ;
			}
		}
		i++;
	}
}

int	check_lines(char *buf, int i, t_info *r_info, int len)
{
	while (*(buf + i) != '\0')
	{
		if (*(buf + i) == '\n')
		{
			if (len != r_info->len)
			{
				write (2, "map error\n", 10);
				return (0);
			}
			else
				len = 0;
			i++;
		}
		while (*(buf + i) != '\n' && *(buf + i) != '\0')
		{
			if (*(buf + i) != r_info->o_c && *(buf + i) != r_info->e_c)
			{
				write (2, "map error\n", 10);
				return (0);
			}
			len++;
			i++;
		}
	}
	return (1);
}

void	get_line_size(char *buf, int i, t_info *r_info)
{
	int	len;

	i++;
	len = 0;
	while (*(buf + i) != '\n')
	{
		if (*(buf + i) != r_info->o_c
			&& *(buf + i) != r_info->e_c)
		{
			write (2, "map error\n", 10);
			return ;
		}
		len++;
		i++;
	}
	r_info->len = len;
	if (check_lines (buf, i, r_info, len))
		buf_to_map(buf, r_info);
}

int	get_info(char *buf, int i, t_info *r_info)
{
	int		j;

	j = 0;
	r_info->ln = 0;
	r_info->f_c = *(buf + --i);
	r_info->o_c = *(buf + --i);
	r_info->e_c = *(buf + --i);
	while (j < i)
	{
		if (*(buf + j) >= '0' && *(buf + j) <= '9')
		{
			r_info->ln = (r_info->ln * 10) + (*(buf + j) - '0');
		}
		else
		{
			r_info->ln = -1;
			break ;
		}
		j++;
	}
	if (r_info->ln < 0)
		return (0);
	else
		return (r_info->f_c != r_info->o_c && r_info->f_c != r_info->e_c
			&& r_info->o_c != r_info->e_c);
}
