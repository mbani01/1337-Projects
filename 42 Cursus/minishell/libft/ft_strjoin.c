/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:17:01 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/21 13:11:15 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strcp(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static	size_t	ft_strl(const char *s)
{
	size_t compt;

	compt = 0;
	while (*s != '\0')
	{
		s++;
		compt++;
	}
	return (compt);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strl(s1);
	j = ft_strl(s2);
	str = malloc(sizeof(char) * (j + i) + 1);
	if (!str)
		return (NULL);
	ft_strcp(str, (char *)s1);
	ft_strcp(str + i, (char *)s2);
	return (str);
}
