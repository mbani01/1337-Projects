/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:18:55 by mbani             #+#    #+#             */
/*   Updated: 2020/11/30 13:10:43 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	red_file_cmd(t_cmd *temp)
{
	int i;

	i = 0;
	if (temp && temp->next && temp->next->next && temp->type != arg && temp->type != cmd && temp->type != semicolumn && temp->type != pipee && temp->next->next->type == arg)
			temp->next->next->type = cmd;
	while (temp->next && temp->next->next)
	{
		if (temp->type == cmd)
			i = 10;
		if (temp->type == semicolumn || temp->type == pipee)
			i = 0;
		if ((temp->type == semicolumn || temp->type == pipee) && temp->next->next->next && ((temp->next->type == input_red || temp->next->type == output_red || temp->next->type  == append_output) && temp->next->next->next->type == arg))
			temp->next->next->next->type = cmd;
		else if ((temp->type == input_red || temp->type == output_red || temp->type  == append_output) && (temp->next->next->type == arg) && i == 0)
			temp->next->next->type = cmd;
		temp = temp->next;
	}
}