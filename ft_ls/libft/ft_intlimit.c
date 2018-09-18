/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlimit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:58:56 by juspende          #+#    #+#             */
/*   Updated: 2018/01/26 13:57:17 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_ebola2(char *str, int neg)
{
	if (str[5] > '8')
		return (0);
	if (str[6] < '3')
		return (1);
	if (str[6] > '3')
		return (0);
	if (str[7] < '6')
		return (1);
	if (str[7] > '6')
		return (0);
	if (str[8] < '4')
		return (1);
	if (str[8] > '4')
		return (0);
	if (neg == 0 && str[9] <= '7')
		return (1);
	if (neg == 1 && str[9] <= '8')
		return (1);
	return (0);
}

static int	get_ebola(char *str, int neg)
{
	if (str[0] < '2')
		return (1);
	if (str[0] > '2')
		return (0);
	if (str[1] < '1')
		return (1);
	if (str[1] > '1')
		return (0);
	if (str[2] < '4')
		return (1);
	if (str[2] > '4')
		return (0);
	if (str[3] < '7')
		return (1);
	if (str[3] > '7')
		return (0);
	if (str[4] < '4')
		return (1);
	if (str[4] > '4')
		return (0);
	if (str[5] < '8')
		return (1);
	return (get_ebola2(str, neg));
}

int			ft_intlimit(char *str)
{
	int		i;
	int		neg;
	int		c;

	i = 0;
	neg = 2;
	c = 0;
	while (str[i] && str[i] == ' ')
		++i;
	while (str[i] == '-' && ++i)
		++neg;
	while (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9' && ++i)
		++c;
	if (c < 10)
		return (1);
	if (c > 10)
		return (0);
	i = 0;
	while (str[i] < '0' || str[i] > '9')
		++i;
	return (get_ebola(&str[i], (neg % 2)));
}
