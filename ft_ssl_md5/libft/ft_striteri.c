/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:20:48 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:20:50 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*str;
	unsigned int	i;

	str = s;
	i = 0;
	if (!s || !f)
		return ;
	while (*str)
	{
		(*f)(i, str);
		str++;
		i++;
	}
}
