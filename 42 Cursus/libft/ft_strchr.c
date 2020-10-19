/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:43:15 by mbani             #+#    #+#             */
/*   Updated: 2019/10/16 12:27:46 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static	size_t	ft_strl(const char *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char			*ft_strchr(const char *s, int c)
{
	char b;
	char *x;

	x = (char *)s;
	b = (unsigned char)c;
	if (b == '\0')
		return (x + ft_strl(x));
	while (*x)
	{
		if (b == *x)
		{
			return (x);
		}
		x++;
	}
	return (NULL);
}
