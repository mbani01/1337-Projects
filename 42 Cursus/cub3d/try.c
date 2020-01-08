/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:45:40 by mbani             #+#    #+#             */
/*   Updated: 2020/01/04 18:50:25 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct		s_list
{
	int			x;
   int y;
	struct s_list	*next;
}					t_list;
t_list	*ft_lstnew(int x, int y)
{
	t_list *ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->x = x;
   ptr->y = y;
	ptr->next = NULL;
	return (ptr);
}
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *p;

	p = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		new->next = NULL;
	}
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
		new->next = NULL;
	}
}
int main()
{
   int x = 0;
   int y = 1;
   int dis;
   int i= 0;
   t_list *p;
   t_list *new;
 p = ft_lstnew(x, y);
   while (i <= 3)
   {
       x++;
       y++;
      new = ft_lstnew(x, y);
      ft_lstadd_back(&p, new);
      i++;
     
      
   }
   while( p != NULL)
   {
   printf("x[%d] y[%d]\n", p->x, p->y);
   p = p->next;
   }
   
   return 0;
}