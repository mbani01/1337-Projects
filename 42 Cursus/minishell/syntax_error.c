/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:14:21 by mbani             #+#    #+#             */
/*   Updated: 2020/11/28 10:34:52 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		syntax_error(t_cmd *temp)
{
	enum e_type tp;

	if (temp->type == semicolumn || temp->type == pipee)
	{
		ft_putstr_fd("bash: syntax error\n", 2);
		return (0);	
	}
	while (temp->next)
	{
		tp = temp->type;
		if ((tp == semicolumn || tp == input_red || tp == output_red || tp == append_output || tp == pipee) && (tp == temp->next->type || (temp->next->type != cmd && temp->next->type != arg )))
		{
			if ((tp == semicolumn || tp == pipee) && (temp->next->type == input_red || temp->next->type == output_red || temp->next->type == append_output))
			{
				temp = temp->next;
				continue;
			}
			ft_putstr_fd("bash: syntax error\n", 2);
			return (0);
		}
		temp = temp->next;
	}
	tp = temp->type;
	if ((tp == input_red || tp == output_red || tp == append_output || tp == pipee) && temp->next == NULL)
	{
		ft_putstr_fd("bash: syntax error\n", 2);
		return (0);
	}
	return (1);
}