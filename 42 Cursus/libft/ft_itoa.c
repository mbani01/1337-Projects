/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 10:54:50 by mbani             #+#    #+#             */
/*   Updated: 2019/10/16 12:51:33 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		ft_count(unsigned int n)
{
	int i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	char	*conv(char *ptr, unsigned int s, int i, int c)
{
	while (s >= 10)
	{
		ptr[--i + c] = ((s % 10) + 48);
		s /= 10;
	}
	if (s < 10)
		ptr[--i + c] = ((s % 10) + 48);
	if (c == 1)
		ptr[--i + c] = 45;
	return (ptr);
}

char			*ft_itoa(int n)
{
	int				i;
	unsigned int	s;
	int				c;
	char			*ptr;

	c = 0;
	if (n < 0)
	{
		c = 1;
		n *= -1;
	}
	s = n;
	i = ft_count(s);
	ptr = (char *)malloc(sizeof(char) * i + 1 + c);
	if (!ptr)
		return (NULL);
	ptr[i + c] = '\0';
	ptr = conv(ptr, s, i, c);
	return (ptr);
}
