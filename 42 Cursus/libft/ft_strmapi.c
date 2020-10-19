/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:35:37 by mbani             #+#    #+#             */
/*   Updated: 2019/10/16 20:07:26 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		ft_sttrlen(const char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*ptr;
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	len = ft_sttrlen(s);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (s[j])
	{
		ptr[i++] = f(j, s[j]);
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
