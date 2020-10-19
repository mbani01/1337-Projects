/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:15:34 by mbani             #+#    #+#             */
/*   Updated: 2019/10/22 22:20:13 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list *p;
	t_list *head;

	head = NULL;
	if (lst)
	{
		if (!(p = malloc(sizeof(t_list))))
			return (NULL);
		head = p;
		p->content = f(lst->content);
		p->next = NULL;
		lst = lst->next;
		while (lst)
		{
			if (!(p = malloc(sizeof(t_list))))
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, p);
			p->content = f(lst->content);
			lst = lst->next;
		}
	}
	return (head);
}
