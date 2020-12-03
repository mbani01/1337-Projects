/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:33:15 by mamoussa          #+#    #+#             */
/*   Updated: 2019/10/22 17:26:00 by mamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ptr;
	t_list *head;

	head = NULL;
	if (lst)
	{
		if (!(ptr = malloc(sizeof(t_list))))
			return (NULL);
		head = ptr;
		ptr->content = f(lst->content);
		ptr->next = NULL;
		lst = lst->next;
		while (lst)
		{
			if (!(ptr = malloc(sizeof(t_list))))
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, ptr);
			ptr->content = f(lst->content);
			lst = lst->next;
		}
	}
	return (head);
}
