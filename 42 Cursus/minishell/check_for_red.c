/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:12:41 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/11 13:22:57 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	in_red(t_cmd *current)
{
	current = current->next;
	if (g_fd_in > 2)
		close(g_fd_in);
	g_fd_in = open(current->string, O_RDONLY);
	if (g_fd_in < 0)
	{
		ft_error(current->string);
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		return (1);
	}
	g_is_in = 1;
	return (0);
}

size_t	app_red(t_cmd *current)
{
	current = current->next;
	if (g_fd_out > 2)
		close(g_fd_out);
	g_fd_out = open(current->string, O_CREAT | O_WRONLY | O_APPEND,
	S_IRUSR | S_IWUSR);
	if (g_fd_out < 0)
	{
		ft_error(current->string);
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		return (1);
	}
	g_is_out = 1;
	return (0);
}

size_t	out_red(t_cmd *current)
{
	current = current->next;
	if (g_fd_out > 2)
		close(g_fd_out);
	g_fd_out = open(current->string, O_CREAT | O_WRONLY | O_TRUNC,
	S_IRUSR | S_IWUSR);
	if (g_fd_out < 0)
	{
		ft_error(current->string);
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		return (1);
	}
	g_is_out = 1;
	return (0);
}

t_cmd	*ptr_to_red(t_cmd *current)
{
	while (current && (current->type != semicolumn) &&
	(current->type != pipee))
	{
		if (current->next && ((current->next->type == input_red) ||
		(current->next->type == output_red)
		|| (current->next->type == append_output)))
			return (current);
		current = current->next;
	}
	return (NULL);
}

size_t	check_for_red(void)
{
	t_cmd	*current;

	current = g_cmd_head;
	while (current && (current->type != semicolumn) &&
	(current->type != pipee))
	{
		if (current->type == input_red)
		{
			if (in_red(current))
				return (1);
		}
		else if (current->type == output_red)
		{
			if (out_red(current))
				return (1);
		}
		else if (current->type == append_output)
		{
			if (app_red(current))
				return (1);
		}
		current = (current) ? current->next : current;
	}
	check_for_red2(current);
	return (0);
}
