/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:39:02 by mamoussa          #+#    #+#             */
/*   Updated: 2019/11/06 12:10:16 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	ptr = malloc(sizeof(char) * ft_strl(s) + 1);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[j] = f(i, s[i]);
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
