/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:41:12 by juspende          #+#    #+#             */
/*   Updated: 2018/01/26 20:10:22 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countspace(char *str)
{
	int		i;
	int		c;

	i = -1;
	c = 0;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == ' ')
			++c;
	return (c + 1);
}
