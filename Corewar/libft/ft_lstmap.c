/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:48:15 by jebossue          #+#    #+#             */
/*   Updated: 2016/11/22 13:52:35 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_dolstmap(t_list *lst, t_list *new,
		t_list *(*f)(t_list *elem))
{
	if (lst)
	{
		new = (*f)(lst);
		new->next = ft_dolstmap(lst->next, new->next, f);
	}
	else
		new = NULL;
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	return (ft_dolstmap(lst, new, f));
}
