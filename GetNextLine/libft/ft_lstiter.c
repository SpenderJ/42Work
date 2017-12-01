/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:59:49 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 18:22:03 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list*tmp;

	tmp = lst;
	if (!lst || !f)
		return ;
	while (tmp->next != NULL)
	{
		f(tmp);
		tmp = tmp->next;
	}
	f(tmp);
}
