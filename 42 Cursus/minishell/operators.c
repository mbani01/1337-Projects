/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:05:47 by mbani             #+#    #+#             */
/*   Updated: 2020/12/11 12:30:50 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				operators(char **line, int i, char **op)
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

int				separators_check(char **tmp, int *i, char **op, int *j)
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
