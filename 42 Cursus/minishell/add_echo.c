/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:15:59 by mbani             #+#    #+#             */
/*   Updated: 2020/12/11 12:26:57 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_lstadd_echo(t_cmd **lst)
{
	t_cmd *tmp_head;
	t_cmd *echo;
	t_cmd *flag;

	tmp_head = lst[0];
	echo = ft_lstnew_cmd("echo", cmd);
	flag = ft_lstnew_cmd("-n", arg);
	echo->next = flag;
	flag->next = tmp_head;
	lst[0] = echo;
}

int		add_echo(t_cmd **lst)
{
	t_cmd *tmp;

	tmp = lst[0];
	if (tmp && tmp->type != cmd)
		ft_lstadd_echo(lst);
	while (tmp)
	{
		if ((tmp->type == pipee || tmp->type == semicolumn) &&
		tmp->next && tmp->next->type != cmd)
			ft_lstadd_echo(&tmp->next);
		tmp = tmp->next;
	}
	return (1);
}
