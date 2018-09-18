/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:58:34 by juspende          #+#    #+#             */
/*   Updated: 2018/04/24 13:35:16 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(tt_list **alst, void (*del)(void *, size_t))
{
	tt_list	*tmp;
	tt_list	*next;

	tmp = *alst;
	while (tmp != NULL)
	{
		next = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}
