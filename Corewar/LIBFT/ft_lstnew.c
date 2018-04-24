/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:50:34 by juspende          #+#    #+#             */
/*   Updated: 2018/04/24 13:35:29 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

tt_list		*ft_lstnew(void const *content, size_t content_size)
{
	tt_list	*elem;

	if ((elem = (tt_list *)malloc(sizeof(tt_list))) == 0)
		return (NULL);
	if (content == NULL)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		elem->content = ft_memcpy(ft_memalloc(content_size + 1),
				content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
