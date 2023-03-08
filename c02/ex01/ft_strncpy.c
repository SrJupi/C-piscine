/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsulzbac <lsulzbac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:25:40 by lsulzbac          #+#    #+#             */
/*   Updated: 2022/04/11 11:47:27 by lsulzbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	counter;
	int				is_src;

	counter = 0;
	is_src = 1;
	while (counter < n)
	{
		if (is_src)
		{
			dest[counter] = src[counter];
			if (src[counter] == '\0')
				is_src = 0;
		}
		else
			dest[counter] = '\0';
		counter++;
	}
	return (dest);
}
