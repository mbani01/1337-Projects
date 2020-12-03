/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:54:49 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/24 17:27:08 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_not_command(void)
{

}

void	ft_execution(char *line, t_cmd *tmp)
{
	while (g_cmd_head)
	{
		if (g_cmd_head->type == cmd)
		{
			if (!ft_strncmp(g_cmd_head->string, "echo", ft_strlen("echo")))
				ft_echo();
			else if (!ft_strncmp(g_cmd_head->string, "cd", ft_strlen("cd")))
				ft_cd();
			else if (!ft_strncmp(g_cmd_head->string, "pwd", ft_strlen("pwd")))
				ft_pwd();
			else if (!ft_strncmp(g_cmd_head->string, "unset", ft_strlen("unset")))
				ft_unset();
			else if (!ft_strncmp(g_cmd_head->string, "export", ft_strlen("export")))
				ft_export();
			else if (!ft_strncmp(g_cmd_head->string, "env", ft_strlen("env")))
				ft_env();
			else if (!ft_strncmp(g_cmd_head->string, "exit", ft_strlen("exit")))
			{
				ft_exit(line, tmp);
			}
			else
				ft_not_builtin();
		}
		else
			ft_not_command();
		g_cmd_head = (g_cmd_head) ? g_cmd_head->next : g_cmd_head;
	}
}
