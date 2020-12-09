/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:54:49 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/09 11:05:27 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_not_command(void)
{
	;
}

void	ft_copy(char *val, char *str, char **tmp, int k)
{
	int x;
	int j;

	x = 0;
	j = k + 2;
	while (val[x])
	{
		tmp[0][k] = val[x];
		k++;
		x++;
	}
	while (str[j])
	{
		tmp[0][k] = str[j];
		k++;
		j++;
	}
}

void	replace_1(char **str, char *val)
{
	int		len;
	int		k;
	char	*tmp;

	k = 0;
	len = ft_strlen(str[0]) + ft_strlen(val);
	tmp = ft_calloc(len, len);
	tmp[len] = '\0';
	while (str[0][k] != 127)
	{
		tmp[k] = str[0][k];
		k++;
	}
	ft_copy(val, str[0], &tmp, k);
	free(str[0]);
	str[0] = NULL;
	str[0] = tmp;
}

void	replace_return_value(t_cmd **str, size_t value)
{
	t_cmd	*tmp;
	int		i;
	char	*val;

	tmp = str[0];
	val = ft_itoa((int)value);
	while (tmp)
	{
		i = 0;
		while (tmp->string[i])
		{
			if (tmp->string[i] == 127)
				replace_1(&tmp->string, val);
			i++;
		}
		tmp = tmp->next;
	}
	free(val);
	val = NULL;
}

void	ft_execution(char *line, t_cmd *tmp)
{
	replace_return_value(&g_cmd_head, 500);
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
