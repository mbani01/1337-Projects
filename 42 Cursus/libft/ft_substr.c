/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:15:14 by mbani             #+#    #+#             */
/*   Updated: 2019/10/22 21:52:15 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;
	char			*a;

	j = 0;
	i = 0;
	if (s == NULL || start > ft_strlen(s))
	{
		a = malloc(sizeof(char));
		a[0] = '\0';
		return (a);
	}
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	s += start;
	while (len > 0 && *s)
	{
		ptr[i++] = *s;
		s++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
