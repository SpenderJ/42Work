/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:17:30 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:17:32 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = 0;
	if ((mem = (void *)malloc(sizeof(*mem) * size)) == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
