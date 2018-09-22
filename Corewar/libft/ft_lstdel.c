/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:52:08 by jebossue          #+#    #+#             */
/*   Updated: 2017/11/01 11:52:27 by jebossue         ###   ########.fr       */
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
