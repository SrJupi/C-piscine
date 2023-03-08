/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:17:46 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/11 15:46:39 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_strlowcase(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

int	is_not_alphanumeric(char letter)
{
	if ((letter >= 48 && letter <= 57)
		|| (letter >= 'A' && letter <= 'Z')
		|| (letter >= 'a' && letter <= 'z'))
		return (0);
	else
		return (1);
}

void	capitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'a')
			str[i] -= 32;
		else if (str[i] >= 'a' && str[i] <= 'z'
			&& is_not_alphanumeric(str[i - 1]))
			str[i] -= 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	ft_strlowcase(str);
	capitalize(str);
	return (str);
}
