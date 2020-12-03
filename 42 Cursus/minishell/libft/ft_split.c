/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:39:27 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/22 11:02:45 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_word(char const *str, char c)
{
	int i;
	int is_c;
	int words;

	is_c = 1;
	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == c)
			is_c = 1;
		else if (is_c == 1)
		{
			words++;
			is_c = 0;
		}
		i++;
	}
	return (words);
}

static	int		ft_countchar(char const *s, char c)
{
	int comp;

	comp = 0;
	while ((s[comp] != '\0') && (s[comp] != c))
	{
		comp++;
	}
	return (comp);
}

char			**ft_memfre(char **ptr, int j)
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
		if (!(ptr[j] = (char *)malloc(sizeof(char) * (ft_countchar(s, c) + 1))))
			return (ft_memfre(ptr, j));
		while (*(char *)s != c && *s)
			ptr[j][a++] = *s++;
		ptr[j++][a] = '\0';
	}
	ptr[j] = 0;
	return (ptr);
}
