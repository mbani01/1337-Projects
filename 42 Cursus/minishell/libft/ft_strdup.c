/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 22:01:15 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/21 13:11:02 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strcp(char *dest, char const *src)
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

char			*ft_strdup(char const *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	return (ft_strcp(str, s1));
}
