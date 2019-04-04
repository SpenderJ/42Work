/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraycmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:50:25 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/22 17:58:09 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strarraycmp(char *str, char **rule)
{
	int	result;

	while ((result = ft_strcmp(str, *(rule)++)) != 0)
		;
	if (result != 0)
		return (result);
	return (1);
}
