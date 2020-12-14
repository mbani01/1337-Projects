/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:38:21 by mbani             #+#    #+#             */
/*   Updated: 2020/12/12 20:38:39 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	delete_pre(void)
{
	int		count;
	int		i;
	char	*tmp;

	count = 0;
	i = 0;
	tmp = ft_strdup(g_line);
	free(g_line);
	g_line = NULL;
	while (count != g_len)
	{
		i++;
		count++;
	}
	g_line = ft_strdup(tmp + i);
	free(tmp);
	tmp = NULL;
}

void	free_g_buff(void)
{
	if (g_buffer)
	{
		free(g_buffer);
		g_buffer = NULL;
	}
}
