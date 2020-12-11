/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:18:55 by mbani             #+#    #+#             */
/*   Updated: 2020/12/11 12:31:22 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	red_file_cmd(t_cmd *temp)
{
	int i;

	i = 0;
	if (temp && temp->next && temp->next->next && temp->type != arg &&
	temp->type != cmd && temp->type != semicolumn && temp->type != pipee
	&& temp->next->next->type == arg)
		temp->next->next->type = cmd;
	while (temp && temp->next && temp->next->next)
	{
		if (temp->type == cmd)
			i = 10;
		if (temp->type == semicolumn || temp->type == pipee)
			i = 0;
		if ((temp->type == semicolumn || temp->type == pipee) &&
		temp->next->next->next && ((temp->next->type == input_red
		|| temp->next->type == output_red || temp->next->type ==
		append_output) && temp->next->next->next->type == arg))
			temp->next->next->next->type = cmd;
		else if ((temp->type == input_red || temp->type == output_red
		|| temp->type == append_output) && (temp->next->next->type
		== arg) && i == 0)
			temp->next->next->type = cmd;
		temp = temp->next;
	}
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
		if ((tmp->type == input_red || tmp->type == output_red ||
		tmp->type == append_output) && tmp->next->type == arg)
			tmp->next->type = filename;
		if ((tmp->type == semicolumn || tmp->type == pipee))
			swap_multi_red(&tmp->next);
		tmp = tmp->next;
	}
	return (1);
}
