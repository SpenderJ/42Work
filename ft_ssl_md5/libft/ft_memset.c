/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:18:09 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:18:11 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*tmp;
	unsigned int	i;

	tmp = s;
	i = 0;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (tmp);
}
