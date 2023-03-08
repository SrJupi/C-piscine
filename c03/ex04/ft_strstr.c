/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:25:37 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/14 20:46:52 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (*(str + i) != '\0')
	{
		j = 0;
		if (*(str + i) == *(to_find + j))
		{
			while (*(str + i) == *(to_find + j))
			{
				if (*(str + i) == '\0' && *(to_find + j) == '\0')
					return (str + (i - j));
				i++;
				j++;
			}
			if (*(to_find + j) == '\0')
				return (str + (i - j));
		}
		i++;
	}
	return (0);
}
