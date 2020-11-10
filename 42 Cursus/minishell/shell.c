/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:54:10 by mbani             #+#    #+#             */
/*   Updated: 2020/11/10 17:21:35 by mbani            ###   ########.fr       */
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
	if (i)
	while (line[i] && line[i - 1] && line[--i] == '\\')
	{
		res++;
	}
	if (res % 2 == 0 || res == 0)
		return (1);
	else
		return (0);
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
		if (line[i] == '\'' && *sngl != 1 && *dbl != 1 && not_escaped(line, i))
			*sngl = opened;
		else if (line[i] == '\'' && *sngl == 1)
			*sngl = closed;
		if (line[i] == '\"' && *dbl != 1 && *sngl != 1 && not_escaped(line, i))
			*dbl = opened;
		else if (line[i] == '\"' && *dbl == 1 && not_escaped(line, i))
			*dbl = closed;
	}
}

int		quoted_str_help(enum e_quotes **sngl,
enum e_quotes **dbl, char **tmp, int i)
{
	*sngl[0] = 0;
	*dbl[0] = 0;
	free(*tmp);
	if (tmp[0][i + 1])
		return (i + 1);
	else
		return (i);
}

int		quoted_str(char *line, enum e_quotes *sngl, enum e_quotes *dbl)
{
	int		i;
	char	*tmp;
	t_cmd	*new;

	i = 0;
	tmp = ft_strdup(line);
	while (line[i++])
	{
		quote_check(sngl, dbl, line, i);
		if ((*sngl == 2 && *dbl != 1) || (*dbl == 2 && *sngl != 1))
		{
			if ((tmp[i + 1] && (tmp[i + 1] == ' ' || tmp[i + 1] == '\t'))
			|| ((tmp[i + 1] == ';' || tmp[i + 1] == '|' ||
			tmp[i + 1] == '<' || tmp[i + 1] == '>')))
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
	return (quoted_str_help(&sngl, &dbl, &tmp, i));
}

void	add_to_list(char **tmp, enum e_type t)
{
	t_cmd	*new;

	new = ft_lstnew_cmd(*tmp, t);
	ft_lstadd_backcmd(&g_cmd_head, new);
	free(*tmp);
	*tmp = NULL;
}

int		operators(char **line, int i, char **op)
{
	int j;

	j = 0;
	op[0] = malloc(3);
	if (line[0][i] == '>' && line[0][i + 1] == '>')
	{
		line[0][i] = '\0';
		line[0][i + 1] = '\0';
		op[0][0] = '>';
		op[0][1] = '>';
		op[0][2] = '\0';
		j = 2;
	}
	else
	{
		op[0][0] = line[0][i];
		op[0][1] = '\0';
		line[0][i] = '\0';
		j = 1;
	}
	return (j);
}

int		separators_check(char **tmp, int *i, char **op, int *j)
{
	if ((tmp[0][*i] == ' ' || tmp[0][*i] == '\t') || ((tmp[0][*i] == ';' ||
		tmp[0][*i] == '|' || tmp[0][*i] == '<' ||
		tmp[0][*i] == '>') && not_escaped(tmp[0], *i)))
	{
		if ((tmp[0][*i] == ' ' || tmp[0][*i] == '\t')
			&& !not_escaped(tmp[0], *i))
		{
			*i += 1;
			return (1);
		}
		if (((tmp[0][*i] == ';' ||
		tmp[0][*i] == '|' || tmp[0][*i] == '<' ||
		tmp[0][*i] == '>') && not_escaped(tmp[0], *i)))
		{
			*i += operators(&tmp[0], *i, &op[0]);
			*j = 1;
			return (0);
		}
		tmp[0][*i] = '\0';
		return (0);
	}
	return (10);
}

enum	e_type	operators_check(char *op)
{
	if (op[0] == '|')
		return (pipee);
	if (op[0] == ';')
		return (semicolumn);
	if (op[0] == '<')
		return (input_red);
	if (op[0] == '>' && op[1] == '\0')
		return (output_red);
	if (op[0] == '>' && op[1] == '>')
		return (append_output);
	return (arg);
}

int		add_to_list_bulk(char **tmp, char **op, int *i, int *j)
{
	static	int x;
	enum e_type t;

	if (x == 0)
		t = cmd;
	else
		t = arg;
	if (*tmp[0])
		add_to_list(tmp, t);
	if (*j == 1 && *op[0])
	{
		t = operators_check(op[0]);
		add_to_list(op, t);
		free(*tmp);
		*tmp = NULL;
	}
	if (t == pipee || t == semicolumn)
		x = 0;
	else
		x = -1;
	*j = 0;
	return (*i);
}

int		add_string(char *line, enum e_quotes *sngl, enum e_quotes *dbl)
{
	int		i;
	int		j;
	int		sep;
	char	*tmp;
	char	*op;

	i = 0;
	tmp = ft_strdup(line);
	while (tmp[i])
	{
		j = 0;
		quote_check(sngl, dbl, tmp, i);
		if (*sngl == 1 || *dbl == 1)
			i += quoted_str(tmp + i, sngl, dbl);
		sep = separators_check(&tmp, &i, &op, &j);
		if (sep == 1)
			continue;
		else if (sep == 0)
			break ;
		i++;
	}
	return (add_to_list_bulk(&tmp, &op, &i, &j));
}

void	line_split(char *line)
{
	enum e_quotes sngl;
	enum e_quotes dbl;
	int		i;

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
	// t_cmd *tmp = g_cmd_head;
	// while (tmp->next)
	// {
	// 	ft_putstr_fd(tmp->string, 1);
		// ft_putstr_fd(" : ", 1);
		// ft_putnbr_fd(tmp->type, 1);
	// 	ft_putchar_fd('\n', 1);
	// 	tmp = tmp->next;
		
	// }
	// ft_putstr_fd(tmp->string, 1);
	// ft_putstr_fd(" : ", 1);
	// ft_putnbr_fd(tmp->type, 1);
	// ft_putchar_fd('\n', 1);
}

// void	quotes_fill(t_expan *expan, char **str, int i)
// {

// }

void replace(char **str, char *env, int j, int i)
{
	char *tmp;
	int k;
	int len;
	int x;

	k = 0;
	x = 0;
	len = ft_strlen(env) + (ft_strlen(str[0]) - (j + 1));
	tmp = ft_calloc(len + 1, len + 1);
	tmp[len] = '\0';
		while (k < (i - j))
		{
			tmp[k] = str[0][k];
			k++;
		}
		len = ft_strlen(env);
		while (len > 0)
		{
			tmp[k] = env[x];
			k++;
			x++;
			len--;
		}
		i++;
		while (str[0][i])
		{
			tmp[k] = str[0][i];
			k++;
			i++;
		}
	free(str[0]);
	str[0] = tmp;
	// ft_putchar_fd('\n', 1);
	// free(tmp);
}

int	ft_strncmp_env(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;
	size_t				i;

	if (n == 0)
		return (0);
	c1 = (unsigned char*)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (c1[i] && c2[i] && c1[i] == c2[i] && n - 1 > i)
		i++;
	if (ft_strlen(s2) == n)
		return (c1[i] - c2[i]);
	return (-1);
}

int	search_and_replace(char **str, int i, int j)
{
	t_env *tmp;

	tmp = g_env_head;
	while (tmp->next)
	{
		if ((ft_strncmp_env(&str[0][i - j + 1], tmp->key, j)) == 0)
		{
			replace(str, tmp->value, j, i);
			// break ;
			return (1);
		}
		tmp = tmp->next;
	}
	if ((ft_strncmp_env(&str[0][i - j + 1], tmp->key, j)) == 0)
	{
		replace(str, tmp->value, j, i);
		return (1);
	}
	return (0);
}

int		char_count(char **str, int i, int *j)
{
	while (str[0][i])
	{
		if (((str[0][i] >= 'a' && str[0][i] <= 'z') ||
		(str[0][i] >= 'A' && str[0][i] <= 'Z')) ||
		(str[0][i] >= '0' && str[0][i] <= '9') || str[0][i] == '_')
			*j += 1;
		else
			break ;
		i++;
	}
	return (*j);
}

void	dolar_check(char **str)
{
	int 	i;
	int		j;
	t_expan expan;

	expan.sng = 0;
	expan.dbl = 0;
	expan.tp = 0;
	i = 0;
	j = 0;
	while (str[0][i])
	{
		quote_check(&expan.sng, &expan.dbl, str[0], i);
		if (expan.sng == 1)
		{
			i++;
			continue;
		}
		else
		{
			if (str[0][i] == '$' && not_escaped(str[0], i))
				i += char_count(str, i + 1, &j);
			if (j)
			{
				if ((search_and_replace(str, i, j)) == 0)
				{
					replace(str, "", j, i);
					i -= j;
				}
				j = 0;
			}
		}
		i++;
	}
}

void	param_expansion(t_cmd *tmp)
{
	while (tmp->next)
	{
		dolar_check(&(tmp->string));
		tmp = tmp->next;
		quote_removal()
	}
	dolar_check(&(tmp->string));
}

void	line_parser(char *line)
{
	g_cmd_head = NULL;
	line = rm_spaces(line);
	line_split(line);
	if (line[0])
	param_expansion(g_cmd_head);
	t_cmd *tmp = g_cmd_head;
	while (tmp->next)
	{
		ft_putstr_fd(tmp->string, 1);
		// ft_putstr_fd(" : ", 1);
		// ft_putnbr_fd(tmp->type, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
		
	}
	ft_putstr_fd(tmp->string, 1);
	// ft_putstr_fd(" : ", 1);
	// ft_putnbr_fd(tmp->type, 1);
	ft_putchar_fd('\n', 1);
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
