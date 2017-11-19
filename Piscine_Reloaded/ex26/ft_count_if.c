/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:06:51 by juspende          #+#    #+#             */
/*   Updated: 2017/11/06 12:06:53 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		i;
	int		ret;
	int		res;

	res = 0;
	ret = 0;
	i = -1;
	if (!tab || !tab[0])
		return (0);
	while (tab[++i] != NULL)
	{
		ret = 0;
		ret = f(tab[i]);
		if (ret == 1)
			res = res + 1;
	}
	return (res);
}
