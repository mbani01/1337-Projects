/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:56:04 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/10 16:43:41 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_pipe	*new_node_index(size_t index)
{
	t_pipe	*new_node;

	new_node = (t_pipe*)malloc(sizeof(t_pipe));
	new_node->index = index;
	new_node->fd0 = 0;
	new_node->fd1 = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_back(t_pipe *new_node)
{
	t_pipe *current;

	current = g_pipe_head;
	if (!g_pipe_head)
	{
		g_pipe_head = new_node;
		new_node->prev = g_pipe_head;
		return ;
	}
	while (current)
	{
		if (!current->next)
		{
			current->next = new_node;
			new_node->prev = current;
			return ;
		}
		current = current->next;
	}
}

void	clear_list(void)
{
	t_pipe	*tmp;

	if (!g_pipe_head)
		return ;
	while (g_pipe_head)
	{
		tmp = g_pipe_head->next;
		if (g_pipe_head->fd0 > 2)
			close(g_pipe_head->fd0);
		if (g_pipe_head->fd1 > 2)
			close(g_pipe_head->fd1);
		free(g_pipe_head);
		g_pipe_head = NULL;
		g_pipe_head = tmp;
	}
}
