/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 12:11:25 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 20:51:21 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		a;
	char	c;

	i = 0;
	a = 0;
	while (str[i] != '\0')
		i = i + 1;
	i = i - 1;
	while (i >= a)
	{
		c = str[i];
		str[i] = str[a];
		str[a] = c;
		a = a + 1;
		i = i - 1;
	}
	return (str);
}
