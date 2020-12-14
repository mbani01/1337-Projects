/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 11:15:20 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/12 14:13:23 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_exec2(char *line, t_cmd *tmp)
{
	if (!ft_strncmp(g_cmd_head->string, "cd", ft_strlen("cd")))
		ft_cd();
	else if (!ft_strncmp(g_cmd_head->string, "exit", ft_strlen("exit")))
		ft_exit(line, tmp);
	else if (!ft_strncmp(g_cmd_head->string, "unset", ft_strlen("unset")))
		ft_unset();
	else if (!ft_strncmp(g_cmd_head->string, "env", ft_strlen("env")))
		ft_env();
	else if (!ft_strncmp(g_cmd_head->string, "export", ft_strlen("export")))
		ft_export();
	else if (!ft_strncmp(g_cmd_head->string, "pwd", ft_strlen("pwd")))
		ft_pwd();
	else if (fork() == 0)
	{
		if (!ft_strncmp(g_cmd_head->string, "echo", ft_strlen("echo")))
			ft_echo();
		else
			ft_not_builtin();
		exit(0);
	}
	close_all();
}

void	ft_exec3(void)
{
	while (wait(&g_status) != -1)
	{
		;
	}
	g_is_cmd = 0;
	if (g_is_sigint && WIFSIGNALED(g_status))
		write(1, "\n", 1);
	if (g_status != 1 && g_status != 127 && g_status != 0)
		g_status = WEXITSTATUS(g_status);
}
