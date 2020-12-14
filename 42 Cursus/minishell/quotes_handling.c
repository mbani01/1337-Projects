/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:00:47 by mbani             #+#    #+#             */
/*   Updated: 2020/12/12 20:31:02 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	quote_removal_init(t_expan *quote, char **tmp, char **temp, int *i)
{
	*i = 0;
	quote->sng = 0;
	quote->dbl = 0;
	if (!(tmp[0] = ft_calloc(1, 1)))
		exit(1);
	if (!(temp[0] = ft_calloc(1, 1)))
		exit(1);
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

void	quote_removal(char **str)
{
	t_expan quote;
	int		i;
	char	*tmp;
	char	*temp;

	quote_removal_init(&quote, &tmp, &temp, &i);
	while (str[0][i])
	{
		temp[0] = str[0][i];
		quote_check(&quote.sng, &quote.dbl, str[0], i);
		if (str[0][i] == '\\' && quote.sng != 1)
			rm_backslash(&temp, str, &tmp, &i);
		else if ((str[0][i] == '\'' && quote.dbl != 1)
		|| (str[0][i] == '\"' && quote.sng != 1) ||
		(str[0][i] == '$' && quote.dbl != 1 && quote.sng != 1 &&
		(str[0][i + 1] == '\'' || str[0][i + 1] == '\"')))
		{
			i++;
			continue ;
		}
		else
			join(&temp, &tmp);
		i++;
	}
	quote_removal_free(str, &tmp, &temp);
}
