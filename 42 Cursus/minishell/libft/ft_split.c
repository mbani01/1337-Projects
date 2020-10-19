/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 20:01:43 by mbani             #+#    #+#             */
/*   Updated: 2019/10/22 12:32:21 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		count_word(char const *str, char c)
{
	int i;

	i = 1;
	if (*str == '\0')
		return (0);
	if (*str == c)
		i = 0;
	while (*str == c)
		str++;
	str -= 1;
	while (*str)
	{
		if ((*str == c) && (*(str + 1) != c))
		{
			if (*(str + 1) != '\0')
				i++;
			str++;
		}
		else
			str++;
	}
	return (i);
}

static	int		ft_cc(char const *s, char c)
{
	int comp;

	comp = 0;
	while ((s[comp] != '\0') && (s[comp] != c))
	{
		comp++;
	}
	return (comp);
}

char			**ft_free(char **ptr, int j)
{
	while (j--)
	{
		free(ptr[j]);
	}
	free(ptr);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**ptr;
	int		j;
	int		a;
	int		i;

	j = 0;
	if (s == NULL)
		return (NULL);
	i = count_word(s, c);
	if (!(ptr = (char **)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	while (i > j)
	{
		a = 0;
		while (*s == c)
			s++;
		if (!(ptr[j] = (char *)malloc(sizeof(char) * ft_cc(s, c) + 1)))
			return (ft_free(ptr, j));
		while (*(char *)s != c && *s)
			ptr[j][a++] = *s++;
		ptr[j++][a] = '\0';
	}
	ptr[j] = 0;
	return (ptr);
}
