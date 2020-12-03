/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_pointer_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:52:11 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/19 19:05:35 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	double_pointer_free(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	ptr = NULL;
}