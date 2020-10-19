/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:29:01 by mbani             #+#    #+#             */
/*   Updated: 2019/10/21 13:24:24 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static	size_t	ftt_strlen(const char *s)
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

static	int		ft_countb(char const *s1, char const *set)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				count++;
				break ;
			}
			else
				j++;
		}
		if (s1[i] != set[j])
			break ;
		i++;
	}
	return (count);
}

static	int		ft_counte(char const *s1, char const *set)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				count++;
				break ;
			}
			else
				j++;
		}
		if (s1[i] != set[j])
			break ;
		i--;
	}
	return (count);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	size_t		k;
	size_t		j;
	size_t		l;
	char		*str;

	j = 0;
	k = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	l = ftt_strlen(s1);
	j = ft_countb((char *)s1, (char *)set);
	if (j != ftt_strlen(s1))
		k = (j + ft_counte((char *)s1 + l - 1, (char *)set));
	str = (malloc(sizeof(char) * (l - k) + 1));
	if (!str)
		return (NULL);
	s1 += j;
	ft_strncpy(str, (char *)s1, l - k);
	return (str);
}
