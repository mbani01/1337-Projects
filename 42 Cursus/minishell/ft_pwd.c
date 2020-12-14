/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:45:49 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/12 14:04:56 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	erro_cheker(void)
{
	if (ft_strncmp("pwd", g_cmd_head->string, ft_strlen(g_cmd_head->string)))
	{
		ft_error("command not found\n");
		g_status = 127;
		return (1);
	}
	g_cmd_head = g_cmd_head->next;
	return (0);
}

void	ft_pwd_helper(char *buf)
{
	if (g_is_out)
	{
		dup2(g_fd_out, 1);
		close(g_fd_out);
	}
	imp_pipes();
	write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	exit(0);
}

void	ft_pwd(void)
{
	char	*buf;
	pid_t	pid;

	buf = NULL;
	if (erro_cheker())
		return ;
	buf = getcwd(buf, 0);
	if (!buf)
	{
		write(2, "Error:", ft_strlen("Error:"));
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		g_status = 1;
		return ;
	}
	if ((pid = fork()) < 0)
		return ;
	if (pid == 0)
		ft_pwd_helper(buf);
	else
		simple_pointer_free(buf);
}
