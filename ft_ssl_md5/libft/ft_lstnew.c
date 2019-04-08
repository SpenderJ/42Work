/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:16:53 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:16:55 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	if ((elem = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	else
		elem->content = content;
	elem->next = NULL;
	return (elem);
}
