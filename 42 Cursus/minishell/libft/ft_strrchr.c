/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:28:21 by mbani             #+#    #+#             */
/*   Updated: 2019/10/22 21:57:07 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	b;
	char	*x;
	int		i;

	b = (char)c;
	i = 0;
	x = (char *)s;
	if (b != '\0' && *x == '\0')
		return (NULL);
	while (*x)
	{
		x++;
		i++;
	}
	if (b == '\0')
		return (x);
	while (i + 1 > 0)
	{
		if (b == *x)
			return (x);
		i--;
		x--;
	}
	return (NULL);
}
