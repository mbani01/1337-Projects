/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:42:41 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/12 16:25:17 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	get_next_line_helper(char *buff)
{
	if (g_buff)
		g_tmp = g_buff;
	g_buff = ft_strdup(buff);
	if (g_tmp)
	{
		free(g_tmp);
		g_tmp = NULL;
	}
}
