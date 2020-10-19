/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 10:54:50 by mbani             #+#    #+#             */
/*   Updated: 2019/11/15 21:58:17 by mbani            ###   ########.fr       */
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

static	char	*conv(char *ptr, unsigned int s, unsigned int i, int c)
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

char			*ft_itoa_u(unsigned int n)
{
	unsigned int	i;
	unsigned int	s;
	int				c;
	char			*ptr;

	c = 0;
	s = n;
	i = ft_count(s);
	ptr = (char *)malloc(sizeof(char) * i + 1 + c);
	if (!ptr)
		return (NULL);
	ptr[i + c] = '\0';
	ptr = conv(ptr, s, i, c);
	return (ptr);
}
