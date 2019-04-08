/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:16:08 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:16:10 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*temp;

	tmp = *alst;
	while (tmp)
	{
		temp = tmp->next;
		(*del)(tmp->content);
		free(tmp);
		tmp = temp;
	}
}
