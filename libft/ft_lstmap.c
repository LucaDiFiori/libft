/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:05:26 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/01/13 11:39:46 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst_node;
	t_list	*head_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst_node = ft_lstnew(f(lst -> content));
	head_node = new_lst_node;
	while (lst -> next)
	{
		lst = lst -> next;
		if (!(lst -> content))
			del(lst -> content);
		new_lst_node -> next = ft_lstnew(f(lst -> content));
		if (!new_lst_node -> next)
		{
			ft_lstclear(&head_node, del);
			return (NULL);
		}
		new_lst_node = new_lst_node -> next;
	}
	return (head_node);
}
