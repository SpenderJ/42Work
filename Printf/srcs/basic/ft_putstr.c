/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:23:13 by juspende          #+#    #+#             */
/*   Updated: 2017/11/22 17:02:41 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include <unistd.h>

void	ft_putstr(char const *s, t_flag *flag)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
		++i;
	flag->charn = flag->charn + i;
	write(1, (char *)s, i);
}
