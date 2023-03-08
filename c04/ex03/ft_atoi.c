/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:08:05 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/21 12:29:50 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	solve_num(char *str, int i, int minuses);

int	ft_atoi(char *str)
{
	int	i;
	int	minuses;

	i = 0;
	minuses = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\v' && str[i] != '\f'
			&& str[i] != '\r' && str[i] != 32
			&& str[i] != '+' && str[i] != '-'
			&& !(str[i] >= '0' && str[i] <= '9'))
			return (0);
		if (str[i] == '-')
			minuses++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			return (solve_num(str, i, minuses));
		}
		i++;
	}
	return (0);
}

int	solve_num(char *str, int i, int minuses)
{
	int	j;
	int	result;

	j = i;
	result = 0;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	while (i < j)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (minuses % 2 == 0)
		return (result);
	else
		return (result * -1);
}
