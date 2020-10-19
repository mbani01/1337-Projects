/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:54:10 by mbani             #+#    #+#             */
/*   Updated: 2020/10/19 11:52:04 by mbani            ###   ########.fr       */
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
			if(env[i] == '=')
			{
				env[i] = '\0';
				*key = ft_strdup(env);
				*value = ft_strdup(&env[i+1]);
			}
			i++;
		}
	return(0);
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
		if(envp[i])
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

void	quote_check(enum e_quotes *sngl, enum e_quotes *dbl, char *line, int i)
{
	if (line[i] == '\'' && *sngl != 1 && line[i - 1] != '\\')
		*sngl = opened;
	if (line[i] == '\'' && *sngl == 1 && line[i - 1] != '\\')
		*sngl = 2;
	if (line[i] == '\"' && *dbl != 1 && line[i - 1] != '\\')
		*dbl = 1;
	if (line[i] == '\"' && *dbl == 1 && line[i - 1] != '\\')
		*dbl = 2;
}

void	add_string(char *tmp, int i, char *line)
{
	t_cmd *new;

	while (tmp[i] != ' ' && tmp[i] != '\t')
		i++;
	tmp[i] = '\0';
	new = ft_lstnew_cmd(tmp);
	ft_lstadd_backcmd(&g_cmd_head, new);
	line +=i;
}

void line_split(char *line)
{
	char *tmp;
	int i;
	enum e_quotes sngl;
	enum e_quotes dbl;

	tmp = ft_strdup(line);
	i = 0;
	sngl = 0;
	dbl = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			quote_check(&sngl, &dbl, line, i);
		if (line[i] == '\\' && sngl != 1)
			i += 2;
		while ((line[i] == ' ' || line[i] == '\t') && sngl !=
		1 && dbl != 1 && line[i - 1] != '\\')
			i++;
		add_string(tmp, i, line);
		// i++;
	}
	free(tmp);
	// ft_printf("hello");
}

void	line_parser(char *line)
{
	line = rm_spaces(line);
	line_split(line);
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
		line_parser(line);
		free(line);
		if (!ret)
			break ;
	}
	ft_lstclearenv(&g_env_head);/* free env var  */
	return (0);
}
