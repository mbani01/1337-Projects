/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imp_pipes_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:06:56 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/10 16:41:20 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	imp_red(void)
{
	if (g_is_in)
	{
		dup2(g_fd_in, 0);
		close(g_fd_in);
	}
	if (g_is_out)
	{
		dup2(g_fd_out, 1);
		close(g_fd_out);
	}
}

void	imp_pipes_helper(void)
{
	if (!g_is_in)
	{
		if (dup2(g_cur->prev->fd0, 0) < 0)
		{
			ft_error(strerror(errno));
			write(2, "\n", 1);
		}
	}
	if (!g_is_out)
	{
		if (dup2(g_cur->fd1, 1) < 0)
		{
			ft_error(strerror(errno));
			write(2, "\n", 1);
		}
		close(g_cur->fd0);
	}
}

void	imp_pipes(void)
{
	if (g_cur->index == 0 && (g_cur->fd1 > 2) && (g_cur->fd0 > 2) && !g_is_out)
	{
		if (dup2(g_cur->fd1, 1) < 0)
		{
			ft_error(strerror(errno));
			write(2, "\n", 1);
		}
		close(g_cur->fd0);
	}
	else if (g_cur->index > 0 && (g_cur->fd1 > 2) && (g_cur->prev->fd0 > 2))
		imp_pipes_helper();
	else if (g_cur->index > 0 && (g_cur->fd1 == 0) && (g_cur->fd0 == 0) &&
	!g_is_in)
	{
		if (dup2(g_cur->prev->fd0, 0) < 0)
		{
			ft_error(strerror(errno));
			write(2, "\n", 1);
		}
	}
}
