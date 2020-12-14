/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:20:47 by mamoussa          #+#    #+#             */
/*   Updated: 2020/12/12 14:25:54 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*equ_search(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

size_t	export_error(t_cmd *current)
{
	char	*ptr_equ;

	ptr_equ = NULL;
	if ((ptr_equ = equ_search(current->string, '=')) &&
	(ptr_equ == current->string))
	{
		if (*(ptr_equ + 1) == '\0')
		{
			ft_error(current->string);
			write(1, " :not a valid identifier\n",
			ft_strlen(" :not a valid identifier\n"));
		}
		else
		{
			ft_error(current->string);
			write(2, " :not a valid identifier\n",
			ft_strlen(" :not a valid identifier\n"));
		}
		g_status = 1;
		return (1);
	}
	return (0);
}

size_t	lexer_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		if (!(str[i] >= '0' && str[i] <= '9') &&
		!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z')
		&& str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	ft_export_2(void)
{
	char	*ptr_to_equ;

	ptr_to_equ = NULL;
	while (g_cmd_head && (g_cmd_head->type != semicolumn) &&
	(g_cmd_head->type != pipee))
	{
		if (lexer_checker(g_cmd_head->string))
		{
			ft_error(g_cmd_head->string);
			write(2, " :not a valid identifier\n",
			ft_strlen(" :not a valid identifier\n"));
			g_status = 1;
			g_cmd_head = g_cmd_head->next;
			continue ;
		}
		if (export_error(g_cmd_head) || (export_pipe_checker()))
		{
			g_cmd_head = g_cmd_head->next;
			continue ;
		}
		if ((ptr_to_equ = ft_strchr(g_cmd_head->string, '=')))
			ft_export_helper(ptr_to_equ);
		g_cmd_head = g_cmd_head->next;
	}
}
