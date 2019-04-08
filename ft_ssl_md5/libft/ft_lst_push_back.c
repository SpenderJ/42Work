/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:15:57 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:15:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lst_push_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
