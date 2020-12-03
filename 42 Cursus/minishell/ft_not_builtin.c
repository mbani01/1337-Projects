/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:08:29 by mamoussa          #+#    #+#             */
/*   Updated: 2020/11/19 17:4 b48y mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	args_count()
{
	size_t	counter;
	t_cmd	*current;

	counter = 0;
	current = g_cmd_head;
	while (current && (current->type != semicolumn) && (current->type != pipee))
	{
		counter++;
		current = current->next;
	}
	return (counter);
}

char	**set_args(size_t	counter)
{
	size_t	i;
	char	**args;
	t_cmd	*current;

	i = 0;
	current = g_cmd_head;
	args = (char**)malloc(sizeof(char*) * (counter + 1));
	while (current && (current->type != semicolumn) &&
	(current->type != pipee))
	{
		args[i] = ft_strdup(current->string);
		i++;
		current = current->next;
	}
	args[i] = NULL;
	return (args);
}

void	check_for_abspath_helper(char **res, char **args
,char *cmd, size_t counter)
{
	g_tmp = res[0];
	res[0] = (res[0][ft_strlen(res[0]) - 1] != '/') ?
	ft_strjoin(res[0], "/") : res[0];
	simple_pointer_free(g_tmp);
	g_tmp = res[0];
	res[0] = ft_strjoin(res[0], cmd);
	simple_pointer_free(g_tmp);
	//simple_pointer_free((g_cmd_head->string));
	g_tmp = g_cmd_head->string;
	g_cmd_head->string = ft_strdup(res[0]);
	simple_pointer_free(g_tmp);
	args = set_args(counter);
	execve(args[0], args, g_tmp_env);
	g_tmp = g_cmd_head->string;
	g_cmd_head->string = ft_strdup(cmd);
	simple_pointer_free(g_tmp);
	double_pointer_free(args);
}

size_t	check_for_abspath(size_t counter)
{
	char	**args;
	char	**res;
	char	*cmd;
	size_t	i;

	i = 0;
	res = path_spliter();
	args = NULL;
	cmd = ft_strdup(g_cmd_head->string);
	while (res[i])
	{
		if (!ft_strncmp(res[i], cmd, ft_strlen(res[i])))
		{
			args = set_args(counter);
			execve(args[0], args, g_tmp_env);
			double_pointer_free(args);
		}
		else
			check_for_abspath_helper(&res[i], args, cmd, counter);
		i++;
	}
	free(cmd);
	double_pointer_free(res);
	return (1);
}

void	ft_not_builtin()
{
	pid_t	pid;
	int		status;
	size_t	counter;

	counter = args_count();
	if ((pid = fork()) < 0)
		exit(0);
	if (pid == 0)
	{
		if (check_for_abspath(counter))
		{
			ft_error("command not found\n");
			exit(0);
		}
	}
	else
		wait(&status);
}
