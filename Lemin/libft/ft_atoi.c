/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 12:47:00 by juspende          #+#    #+#             */
/*   Updated: 2018/01/28 18:30:54 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		set_result(int *result)
{
	*result = -2147483648;
	return (0);
}

int				ft_atoii(const char *str, int *result)
{
	int		sign;

	*result = 0;
	sign = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (set_result(result));
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '-' ? -1 : 1);
		str++;
	}
	if (*str == '\0')
		return (0);
	while ('0' <= *str && *str <= '9')
	{
		*result = (*result * 10) + (*str - '0');
		str++;
	}
	*result = sign == -1 ? -(*result) : *result;
	if (*str != '\0')
		return (0);
	return (1);
}

int		ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	c;
	int	d;

	a = 0;
	i = -1;
	c = 1;
	d = 0;
	while (str[++i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			a = 1;
	if (str[i] == '\0' || str[i] < '0' || str[i] > '9')
		return (-30071998);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		d = (d * c) + (str[i++] - 48);
		c = 10;
	}
	return ((a == 0) ? d : -d);
}
