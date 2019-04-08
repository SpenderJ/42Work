/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraycmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:19:30 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:19:34 by juspende         ###   ########.fr       */
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
