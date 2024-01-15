/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:29:34 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/01/13 11:55:54 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *source, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(*to_find))
		return ((char *)source);
	if (!len || !(*source))
		return (NULL);
	while (source[i] && len)
	{
		while ((j < len && to_find[j] && to_find[j] == source[i + j]))
			j++;
		if (to_find[j] == '\0')
			return ((char *)&source[i]);
		i++;
		j = 0;
		len--;
	}
	return (NULL);
}
