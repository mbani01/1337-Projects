/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:16:39 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/09 20:55:22 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*check_for_slash(char *str)
{
	while (*str)
	{
		if (*str == '/')
			return (str);
		str++;
	}
	return (NULL);
}
