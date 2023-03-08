/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:06:27 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/14 20:31:41 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	i;
	unsigned int	j;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size < dest_size)
		return (size + src_size);
	else
	{
		i = dest_size;
		j = 0;
		while (i < (size - 1)
			&& *(src + j) != '\0')
		{
			*(dest + i) = *(src + j);
			i++;
			j++;
		}
		*(dest + i) = '\0';
	}
	return (dest_size + src_size);
}
