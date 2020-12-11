/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:14:21 by mbani             #+#    #+#             */
/*   Updated: 2020/12/11 12:32:38 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		syntax_error_ext(t_cmd **temp)
{
	enum e_type tp;

	while (temp[0] && temp[0]->next)
	{
		tp = temp[0]->type;
		if ((tp == semicolumn || tp == input_red || tp == output_red ||
		tp == append_output || tp == pipee) && (tp == temp[0]->next->type ||
		(temp[0]->next->type != cmd && temp[0]->next->type != arg)))
		{
			if ((tp == semicolumn || tp == pipee) &&
			(temp[0]->next->type == input_red
			|| temp[0]->next->type == output_red ||
			temp[0]->next->type == append_output))
			{
				temp[0] = temp[0]->next;
				continue;
			}
			ft_putstr_fd("bash: syntax error\n", 2);
			return (0);
		}
		temp[0] = temp[0]->next;
	}
	return (1);
}

int		syntax_error(t_cmd *temp)
{
	enum e_type tp;

	if (temp && (temp->type == semicolumn || temp->type == pipee))
	{
		ft_putstr_fd("bash: syntax error\n", 2);
		return (0);
	}
	if (!syntax_error_ext(&temp))
		return (0);
	if (temp)
		tp = temp->type;
	if (temp && (tp == input_red || tp == output_red ||
	tp == append_output || tp == pipee) && temp->next == NULL)
	{
		ft_putstr_fd("bash: syntax error\n", 2);
		return (0);
	}
	return (1);
}
