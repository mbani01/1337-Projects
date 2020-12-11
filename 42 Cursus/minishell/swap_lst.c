/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:47:24 by mbani             #+#    #+#             */
/*   Updated: 2020/12/11 13:16:21 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		find_red(t_cmd **tmp_red, t_cmd **lst)
{
	t_cmd *tmp;

	tmp = lst[0];
	tmp_red[0] = NULL;
	while (tmp && tmp->type != pipee && tmp->type != semicolumn)
	{
		if (tmp->type == input_red ||
		tmp->type == output_red || tmp->type == append_output)
		{
			tmp_red[0] = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp_red[0])
		return (1);
	else
		return (0);
}

int		find_cmd_red(t_cmd **tmp_before_cmd, t_cmd **tmp_red, t_cmd **lst)
{
	t_cmd *tmp;

	tmp_before_cmd[0] = NULL;
	tmp_red[0] = NULL;
	tmp = lst[0];
	if (tmp->type == cmd)
		tmp_before_cmd[0] = tmp;
	while (tmp && tmp->type != pipee && tmp->type != semicolumn)
	{
		if (tmp->next && tmp->next->type == cmd)
			tmp_before_cmd[0] = tmp;
		tmp = tmp->next;
	}
	find_red(tmp_red, lst);
	if (tmp_before_cmd[0] && tmp_red[0])
		return (1);
	else
		return (0);
}

void	arg_found(t_cmd **tmp_arg, t_cmd **tmp_before_arg, t_cmd **tmp_cmd)
{
	tmp_arg[0] = ft_lstnew_cmd(tmp_before_arg[0]->next->string,
	tmp_before_arg[0]->next->type);
	ft_lstadd_backcmd(tmp_cmd, tmp_arg[0]);
	ft_lstclearnod(tmp_before_arg[0], tmp_before_arg[0]->next->next);
}

void	first_ele_arg(t_cmd **tmp_arg, t_cmd **tmp_before_arg, t_cmd **tmp_cmd)
{
	t_cmd *tmp_lst;

	tmp_arg[0] = ft_lstnew_cmd(tmp_before_arg[0]->string,
	tmp_before_arg[0]->type);
	tmp_lst = tmp_before_arg[0]->next;
	free(tmp_before_arg[0]->string);
	tmp_before_arg[0]->string = NULL;
	free(tmp_before_arg[0]);
	tmp_before_arg[0] = NULL;
	tmp_before_arg[0] = tmp_lst;
	ft_lstadd_backcmd(tmp_cmd, tmp_arg[0]);
}

int		find_args(t_cmd **tmp_before_arg, t_cmd **tmp_arg,
t_cmd **tmp_cmd, t_cmd **lst)
{
	tmp_before_arg[0] = lst[0];
	tmp_arg[0] = NULL;
	while (tmp_before_arg[0]->next && tmp_before_arg[0]->next->type
	!= semicolumn && tmp_before_arg[0]->next->type != pipee)
	{
		if (tmp_before_arg[0]->type == arg)
		{
			first_ele_arg(tmp_arg, tmp_before_arg, tmp_cmd);
			continue;
		}
		if (tmp_before_arg[0]->type == semicolumn
		|| tmp_before_arg[0]->type == pipee)
			break ;
		if (tmp_before_arg[0]->next->type == arg)
		{
			arg_found(tmp_arg, tmp_before_arg, tmp_cmd);
			continue;
		}
		tmp_before_arg[0] = tmp_before_arg[0]->next;
	}
	if (tmp_arg[0])
		return (1);
	else
		return (0);
}
