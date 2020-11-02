/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:54:10 by mbani             #+#    #+#             */
/*   Updated: 2020/11/02 10:45:12 by mbani            ###   ########.fr       */
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

int		not_escaped(char *line, int i)
{
	int res;

	res = 0;
	while (line[i] && line[--i] == '\\')
	{
		res++;
	}
	if (res % 2 == 0 || res == 0)
		return 1;
	else
		return 0;
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
	return (line);
}

void	quote_check(enum e_quotes *sngl, enum e_quotes *dbl, char *line, int i)
{
	if (i == 0 || line[i - 1])
	{
		if (line[i] == '\'' && *sngl != 1 && not_escaped(line, i))
			*sngl = opened;
		else if (line[i] == '\'' && *sngl == 1)
			*sngl = closed;
		if (line[i] == '\"' && *dbl != 1 && not_escaped(line, i) && *sngl != 1)
			*dbl = opened;
		else if (line[i] == '\"' && *dbl == 1 && not_escaped(line, i))
			*dbl = closed;
	}
}

int quoted_str(char *line, enum e_quotes *sngl, enum e_quotes *dbl)
{
	int i;
	char *tmp;
	t_cmd *new;

	i = 0;
	tmp = ft_strdup(line);
	while (line[i++])
	{
		quote_check(sngl, dbl, line, i);
		if ((*sngl == 2 && *dbl != 1) || (*dbl == 2 && *sngl != 1))
		{
			if (tmp[i + 1] && (tmp[i + 1] == ' ' || tmp[i + 1] == '\t'))
			{
				tmp[i + 1] = '\0';
				break ;
			}
			else if (tmp[i + 1])
				continue ;
			else
				break ;
		}
	}
	*sngl = 0;
	*dbl = 0;
	free(tmp);
	return (i + 1);
}

void add_to_list(char **tmp)
{
	t_cmd	*new;

	new = ft_lstnew_cmd(*tmp);
	ft_lstadd_backcmd(&g_cmd_head, new);
	free(*tmp);
}
int	operators(char **line, int i)
{
	char *op;
	char *tmp;
	int j;

	j = 0;
	op = malloc(2);
	tmp = ft_strdup(*line);
	if (tmp[i + 1] == '>' && tmp[i + 2] == '>')
	{
		tmp[i + 1] = '\0';
		tmp[i + 2] = '\0';
		op[0] = '>';
		op[1] = '>';
		j += 3;
	}
	else
	{
		op[0] = tmp[i + 1];
		op[1] = '\0';
		tmp[i + 1] = '\0';
		j += 2;
	}
	free(*line);
	*line = ft_strdup(&tmp[i + j]);
	add_to_list(&tmp);
	add_to_list(&op);
	return i + j;
}

int		add_string(char *line, enum e_quotes *sngl, enum e_quotes *dbl)
{
	int		i;
	char	*tmp;
	int 	j;

	i = 0;
	j = 0;
	tmp = ft_strdup(line);
	while (tmp[i])
	{
		quote_check(sngl, dbl, tmp, i);
		if (*sngl == 1 || *dbl == 1)
		{
			j = 0;
			i += quoted_str(tmp + i, sngl, dbl);
		}
		if ((tmp[i] == ';' || tmp[i] == '|' || tmp[i] == '<' || tmp[i] == '>') && not_escaped(tmp, i))
			{
				i += operators(&tmp, i - 1);
				j += i;
				i = 0;
				continue;
			}
		if ((tmp[i] == ' ' || tmp[i] == '\t'))
		{
			j = 0;
			if (!not_escaped(tmp, i))
			{
				i++;
				continue;
			}
			tmp[i] = '\0';
			break ;
		}
		i++;
	}
	i = ft_strlen(tmp);
	add_to_list(&tmp);
	return (i + j);
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
		if (line[i])
			i += add_string(line + i, &sngl, &dbl);
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
	free(line);
	ft_lstclearenv(&g_env_head);/* free env var  */
	return (0);
}
