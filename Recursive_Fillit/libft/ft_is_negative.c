/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 11:38:57 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 20:57:26 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_is_negative(int n)
{
	if (n >= 0)
		ft_putchar('P');
	else
		ft_putchar('N');
}
