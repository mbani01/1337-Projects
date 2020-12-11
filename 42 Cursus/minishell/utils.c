/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:08:11 by mbani             #+#    #+#             */
/*   Updated: 2020/12/11 17:58:51 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*rm_spaces(char *line)
{
	int		i;
	int		len;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	line += i;
	len = ft_strlen(line) - 1;
	i = len;
	return (line);
}

void	cp_before_dlr(int *k, int len, char **tmp, char **str)
{
	while (*k < len)
	{
		tmp[0][*k] = str[0][*k];
		*k += 1;
	}
}

void	cp_from_dlr(int *k, char **tmp, char **env, int *x)
{
	int len;

	len = ft_strlen(env[0]);
	while (len > 0)
	{
		tmp[0][*k] = env[0][*x];
		*k += 1;
		*x += 1;
		len--;
	}
}

void	replace(char **str, char *env, int j, int i)
{
	char	*tmp;
	int		k;
	int		len;
	int		x;

	k = 0;
	x = 0;
	len = ft_strlen(env) + (ft_strlen(str[0]) - (j + 1));
	tmp = ft_calloc(len + 1, len + 1);
	tmp[len] = '\0';
	cp_before_dlr(&k, (i - j), &tmp, str);
	cp_from_dlr(&k, &tmp, &env, &x);
	i++;
	while (str[0][i])
	{
		tmp[k] = str[0][i];
		k++;
		i++;
	}
	free(str[0]);
	str[0] = tmp;
}

int		search_and_replace(char **str, int i, int j)
{
	t_env	*tmp;
	char	ret[1];

	tmp = g_env_head;
	ret[0] = 127;
	if (str[0][i - j + 1] == '?')
	{
		search_and_replace_help(str, i, j);
		return (1);
	}
	while (tmp->next)
	{
		if ((ft_strncmp_env(&str[0][i - j + 1], tmp->key, j)) == 0)
		{
			replace(str, tmp->value, j, i);
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
