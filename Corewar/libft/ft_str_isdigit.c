/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:39:08 by jebossue          #+#    #+#             */
/*   Updated: 2017/11/01 11:40:52 by jebossue         ###   ########.fr       */
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
