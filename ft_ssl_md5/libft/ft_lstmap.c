/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:16:48 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:16:49 by juspende         ###   ########.fr       */
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
