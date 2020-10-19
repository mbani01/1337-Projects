/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:06:48 by mbani             #+#    #+#             */
/*   Updated: 2019/10/19 13:33:43 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	size_t	ft_sstrlen(const char *s)
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

static	char	*ft_sstrcpy(char *dest, char *src)
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

char			*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	char			*s3;
	unsigned int	len1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_sstrlen(s1);
	len = len1 + ft_sstrlen(s2);
	s3 = (char *)malloc(sizeof(char) * len + 1);
	if (!s3)
		return (NULL);
	ft_sstrcpy(s3, (char *)s1);
	s3 += len1;
	ft_sstrcpy(s3, (char *)s2);
	return (s3 - len1);
}
