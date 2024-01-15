/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 09:37:25 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/01/13 10:34:39 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Deletes and frees the given node and every successor of that node*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_node;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp_node = (*lst)-> next;
		ft_lstdelone((*lst), del);
		*lst = temp_node;
	}
}
