/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:54:10 by mbani             #+#    #+#             */
/*   Updated: 2020/10/24 16:57:13 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "shell.h"

int	env_spliter(char *env, char **key, char **value)
{
	int i;

	i = 0;
	if (env)
		while (env[i])
		{
			if (env[i] == '=')
			{
				env[i] = '\0';
				*key = ft_strdup(env);
				*value = ft_strdup(&env[i+1]);
			}
			i++;
		}
	return (0);
}

void	env_var(char **envp)
{
	int		i;
	t_env	*new;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i])
	{
		if (envp[i])
			env_spliter(envp[i], &key, &value);
		i++;
		new = ft_lstnewenv(key, value);
		ft_lstadd_backenv(&g_env_head, new);
	}
}

char	*rm_spaces(char *line)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	line += i;
	len = ft_strlen(line) - 1;
	i = len;
	/* 
	if ((line[len] == ' ' || line[len] == '\t') && line[len - 1] != '\\')
	// {
	// 	while ((line[i] == ' ' || line[i] == '\t') && line[i - 1]  != '\\')
	// 		i--;
	// 		line[len- (len - i) + 1] = '\0';
	// 	return (line);
	// }   remove end line spaces needed to check special characters before space
	*/ 
	return (line);
}

int		not_escaped(char *line, int i)
{
	int res;
	while(line[i] && line[--i] == '\\')
	{
		res++;
	}
	if(res % 2 == 0)
		return 0;
	else
		return 1;
}

void	quote_check(enum e_quotes *sngl, enum e_quotes *dbl, char *line, int i)
{
	if (i == 0 || line[i-1])
	{
	if (line[i] == '\'' && *sngl != 1 && line[i - 1] != '\\')
		*sngl = opened;
	else if (line[i] == '\'' && *sngl == 1)
		*sngl = closed;
	if (line[i] == '\"' && *dbl != 1 && line[i - 1] != '\\')
		*dbl = opened;
	else if (line[i] == '\"' && *dbl == 1 && line[i - 1] != '\\')
		*dbl = closed;
	}
}

int		add_string(char *line)
{
	t_cmd	*new;
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(line);
	while (tmp[i++])
	{
		if (tmp[i] == ' ' || tmp[i] == '\t')
		{
			tmp[i] = '\0';
			break ;
		}
	}
	new = ft_lstnew_cmd(tmp);
	ft_lstadd_backcmd(&g_cmd_head, new);
	i = ft_strlen(tmp);
	free(tmp);
	return (i);
}

int quoted_str(char *line, enum e_quotes *sngl, enum e_quotes *dbl)
{
	int i;
	char *tmp;
	t_cmd *new;

	i = 0;
	tmp = ft_strdup(line);
	while (line[++i])
	{
		quote_check(sngl, dbl, line, i);
		if ((*sngl == 2 && *dbl != 1) || (*dbl == 2 && *sngl != 1))
		{
			if (tmp[i + 1] && (tmp[i + 1] == ' ' || tmp[i + 1] == '\t'))
			{
				tmp[i + 1] = '\0';
				break ;
			}
			else if(tmp[i + 1])
				continue ;
			else
				break ;
		}
	}
	new = ft_lstnew_cmd(tmp);
	ft_lstadd_backcmd(&g_cmd_head, new);
	free(tmp);
	*sngl = 0;
	*dbl = 0;
	return i + 1;
}

void	line_split(char *line)
{
	int i;
	enum e_quotes sngl;
	enum e_quotes dbl;

	i = 0;
	sngl = 0;
	dbl = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		// if(line[i] == '\\')
		// 	backslash(line, i);
		quote_check(&sngl, &dbl, line, i);
		if (sngl == 1 || dbl == 1)
		{
			i += quoted_str(line + i, &sngl, &dbl);
		}
		else
		{
			i += add_string(line + i);
		}
	}
	t_cmd *tmp = g_cmd_head;
	while (tmp->next)
	{
		ft_putstr_fd(tmp->string, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
	ft_putstr_fd(tmp->string, 1);
	ft_putchar_fd('\n', 1);
}

void	line_parser(char *line)
{
	g_cmd_head = NULL;
	line = rm_spaces(line);
	line_split(line);
	if (g_cmd_head)
	ft_lstclearcmd(&g_cmd_head);
	// ft_putstr_fd(line, 1);
	// ft_putchar_fd('\n', 1);
}

int		main(int argc, char  **argv, char **envp)
{
	int ret;
	char *line;

	env_var(envp);
	while (1)
	{
		write(1, "Minishell-2.0$ ", 15);
		ret = get_next_line(0, &line);
		if (!ret)
			break ;
		line_parser(line);
		free(line);
	}
	ft_lstclearenv(&g_env_head);/* free env var  */
	return (0);
}
