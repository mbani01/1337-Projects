/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:54:49 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/12 11:43:50 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	glob_var_init(void)
{
	g_fd_in = 0;
	g_fd_out = 0;
	g_is_in = 0;
	g_is_out = 0;
}

void	ft_exec_helper(void)
{
	t_cmd	*current;
	t_pipe	*new_node;
	size_t	index;

	g_pipe_head = NULL;
	current = g_cmd_head;
	index = 0;
	while (current)
	{
		if (current->type == cmd)
		{
			new_node = new_node_index(index);
			add_back(new_node);
			index++;
		}
		else if (current->type == semicolumn)
			index = 0;
		current = current->next;
	}
}

void	close_all(void)
{
	if (g_cur->index == 0 && (g_cur->fd0 > 2) && (g_cur->fd1 > 2))
		close(g_cur->fd1);
	else if (g_cur->index > 0 && (g_cur->fd0 > 2) && (g_cur->fd1 > 2))
	{
		close(g_cur->prev->fd0);
		close(g_cur->fd1);
	}
	else if (g_cur->prev->fd0 > 2)
		close(g_cur->prev->fd0);
	if (g_fd_in > 2)
		close(g_fd_in);
	if (g_fd_out > 2)
		close(g_fd_out);
}

void	free_pipe(void)
{
	t_pipe *tmp;

	while (g_pipe_head)
	{
		tmp = g_pipe_head->next;
		free(g_pipe_head);
		g_pipe_head = NULL;
		g_pipe_head = tmp;
	}
}

void	ft_execution(char *line, t_cmd *tmp)
{
	ft_exec_helper();
	g_cur = g_pipe_head;
	while (g_cmd_head)
	{
		param_expansion(g_cmd_head);
		replace_return_value(&g_cmd_head, g_status);
		if (ft_exec1(line, tmp))
			return ;
		g_cmd_head = (g_cmd_head) ? g_cmd_head->next : g_cmd_head;
	}
	free_pipe();
}
