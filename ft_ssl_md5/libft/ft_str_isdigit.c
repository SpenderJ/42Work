/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:19:25 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:19:27 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isdigit(const char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] && !ft_isdigit(s[i]))
		return (0);
	return (1);
}
