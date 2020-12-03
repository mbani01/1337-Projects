/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:47:24 by mbani             #+#    #+#             */
/*   Updated: 2020/12/02 18:50:14 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_lstclearnod(t_cmd *back, t_cmd *next)
{
	t_cmd *temp;

	temp = back->next;
	back->next = next;
	free(temp->string);
	temp->string = NULL;
	free(temp);
	temp = NULL;
}

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

void		arg_found(t_cmd **tmp_arg, t_cmd **tmp_before_arg, t_cmd **tmp_cmd)
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

void	start_cmd(t_cmd **tmp_red, t_cmd **tmp_before_arg,
t_cmd **tmp_arg, t_cmd **lst)
{
	t_cmd *tmp_cmd;
	t_cmd *tmp_lst;

	tmp_cmd = ft_lstnew_cmd(lst[0]->string, lst[0]->type);
	tmp_lst = lst[0]->next;
	free(lst[0]->string);
	lst[0]->string = NULL;
	free(lst[0]);
	lst[0] = NULL;
	lst[0] = tmp_lst;
	if (!find_args(tmp_before_arg, tmp_arg, &tmp_cmd, lst))
	{
		tmp_lst = lst[0];
		lst[0] = tmp_cmd;
		tmp_cmd->next = tmp_lst;
		return ;
	}
	tmp_arg[0]->next = tmp_red[0];
	lst[0] = tmp_cmd;
	tmp_cmd = NULL;
	tmp_lst = NULL;
}

void	cmd_in_middle(t_cmd **tmp_red, t_cmd **tmp_before_cmd,
t_cmd **tmp_before_arg, t_cmd **lst)
{
	t_cmd *tmp_cmd;
	t_cmd *tmp_arg;
	t_cmd *tmp_lst;

	tmp_cmd = ft_lstnew_cmd(tmp_before_cmd[0]->next->string,
	tmp_before_cmd[0]->next->type);
	tmp_lst = tmp_before_cmd[0]->next->next;
	free(tmp_before_cmd[0]->next->string);
	tmp_before_cmd[0]->next->string = NULL;
	free(tmp_before_cmd[0]->next);
	tmp_before_cmd[0]->next = NULL;
	tmp_before_cmd[0]->next = tmp_lst;
	if (!find_args(tmp_before_arg, &tmp_arg, &tmp_cmd, lst))
	{
		tmp_cmd->next = tmp_red[0];
		lst[0] = tmp_cmd;
		return ;
	}
	tmp_arg->next = tmp_red[0];
	lst[0] = tmp_cmd;
}

void	swap_multi_red(t_cmd **lst)
{
	t_cmd *tmp_red;
	t_cmd *tmp_before_cmd;
	t_cmd *tmp_before_arg;
	t_cmd *tmp_arg;

	if (!find_cmd_red(&tmp_before_cmd, &tmp_red, lst))
		return ;
	if (tmp_before_cmd == lst[0])
	{
		start_cmd(&tmp_red, &tmp_before_arg, &tmp_arg, lst);
	}
	else
	{
		cmd_in_middle(&tmp_red, &tmp_before_cmd, &tmp_before_arg, lst);
	}
}

int		swap_lst(t_cmd **cmd_lst)
{
	t_cmd *tmp;
	t_cmd *tmp2;

	tmp = cmd_lst[0];
	tmp2 = cmd_lst[0];
	while (tmp2)
	{
		if ((tmp2->type == input_red || tmp2->type == output_red ||
		tmp2->type == append_output) && tmp2->next->type == arg)
			tmp2->next->type = filename;
		tmp2 = tmp2->next;
	}
	swap_multi_red(cmd_lst);
	tmp = cmd_lst[0];
	while (tmp->next)
	{
		if((tmp->type == input_red || tmp->type == output_red ||
		tmp->type == append_output) && tmp->next->type == arg)
			tmp->next->type = filename;
		if ((tmp->type == semicolumn || tmp->type == pipee))
			swap_multi_red(&tmp->next);
		tmp = tmp->next;
	}
	return (1);
}
