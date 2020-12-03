/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:01:10 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/23 11:30:31 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_error(const char* error)
{
	write(1, "bash: ", ft_strlen("bash: "));
	write(1, error, ft_strlen(error));
}