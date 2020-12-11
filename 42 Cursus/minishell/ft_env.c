/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:52:12 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/10 12:27:14 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	ft_env_helper(void)
{
	if (ft_strncmp("env", g_cmd_head->string, ft_strlen(g_cmd_head->string)))
	{
		ft_error(g_cmd_head->string);
		write(2, ": command not found\n", ft_strlen(": command not found\n"));
		g_status = 127;
		return (1);
	}
	return (0);
}

void	ft_env_helper2(t_env *current)
{
	if (g_is_out)
	{
		dup2(g_fd_out, 1);
		close(g_fd_out);
	}
	imp_pipes();
	while (current)
	{
		write(1, current->key, ft_strlen(current->key));
		write(1, "=", 1);
		write(1, current->value, ft_strlen(current->value));
		write(1, "\n", 1);
		current = current->next;
	}
	exit(0);
}

void	ft_env(void)
{
	t_env	*current;
	pid_t	pid;

	if (ft_env_helper())
		return ;
	g_cmd_head = g_cmd_head->next;
	if (g_cmd_head && g_cmd_head->type != semicolumn &&
	g_cmd_head->type != pipee)
	{
		write(2, "env: ", ft_strlen("env: "));
		write(2, g_cmd_head->string, ft_strlen(g_cmd_head->string));
		write(2, ": No such file or directory\n",
		ft_strlen(": No such file or directory\n"));
		g_status = 127;
		return ;
	}
	current = g_env_head;
	if ((pid = fork()) < 0)
		return ;
	if (pid == 0)
		ft_env_helper2(current);
}
