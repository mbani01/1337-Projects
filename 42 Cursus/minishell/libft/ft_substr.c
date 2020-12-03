/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:20:38 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/22 11:17:38 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (start > ft_strlen(s))
	{
		if (!(str = malloc(sizeof(char))))
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	s += start;
	while (*s && len > 0)
	{
		str[i] = *s;
		i++;
		s++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
