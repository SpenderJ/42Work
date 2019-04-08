/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzerocustom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:14:58 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:14:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzerocustom(void *s, size_t n, char c)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s + n);
}
