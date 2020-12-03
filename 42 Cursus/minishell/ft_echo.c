/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:03:41 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/24 18:01:47 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	check_for_n()
{
	t_cmd	*current;

	current = g_cmd_head;
	while (current && (current->type != semicolumn) && (current->type != pipee))
	{
		if	(!ft_strncmp(g_cmd_head->string, "-n", ft_strlen("-n")))
			return (1);
		current = current->next;
	}
	return (0);
}

void	input_out_red()
{
	t_cmd	*current;

	current = g_cmd_head;
	while (current && (current->type != semicolumn) && (current->type != pipee))
	{
	    if	(current->type == input_red)	
		{
			current = current->next;
			//check for permession first
			g_int_fd = open(current->string, O_RDONLY);
			close(g_int_fd);
		}
		else if (current->type == output_red)
		{
			current = current->next;
			//check for file permessions first
			g_out_fd = open(current->string, O_CREAT | O_WRONLY | O_TRUNC);
			//check the errors if g_out_fd  < 0
			int tmp = dup(g_out_fd);	
			dup2(g_out_fd, 1);
			close(tmp);
		}
		else if (current->type == append_output)
		{
			current = current->next;
			//check for file permessions first
			g_out_fd = open(current->string, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU | S_IRWXG);
			//check the errors if g_out_fd < 0
			if (g_out_fd < 0)
			{
				ft_error("not such file or directory\n");
				exit(0);
			}
			dup2(g_out_fd, 1);
			close(g_out_fd);
		}
		current = current->next;
	}
}

void	ft_echo_helper(void)
{
	size_t	is_n;

	is_n = 0;
	g_cmd_head = g_cmd_head->next;
	input_out_red();
	if (!g_cmd_head || (g_cmd_head->type == semicolumn) || (g_cmd_head->type == pipee))
	{
		write(1, "\n", 1);
		exit(0);
	}
	is_n = check_for_n();
	if (is_n)
		g_cmd_head = g_cmd_head->next;
	while (g_cmd_head && (g_cmd_head->type != semicolumn) && (g_cmd_head->type != pipee))
	{
		write(1, g_cmd_head->string, ft_strlen(g_cmd_head->string));
		g_cmd_head = g_cmd_head->next;
		if (g_cmd_head && (g_cmd_head->type != semicolumn) && (g_cmd_head->type != pipee))
			write(1, " ", 1);
	}
	if (!is_n)
		write(1, "\n", 1);
	free(g_line);
	// ft_lstclearcmd(&g_tmp_cmd);
	exit(0);
}

void	ft_echo()
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) < 0)
		return ;
	if (pid == 0)
		ft_echo_helper();
	else
		wait(&status);
}
