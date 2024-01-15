/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:27:28 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/01/13 09:32:52 by ldi-fior         ###   ########.fr       */
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
	if (!new_lst_node)
		return (NULL);
	head_node = new_lst_node;
	while (lst)
	{
		lst = lst -> next;
		new_lst_node -> next = ft_lstnew(f(lst -> content));
		if (!new_lst_node -> next)
		{
			ft_lstclear(&head_node, del);
			return (NULL);
		}
		del(lst -> content);
		new_lst_node = new_lst_node -> next;
	}
	return (head_node);
}
