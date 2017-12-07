/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:23:13 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 20:17:48 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstrr(char const *s)
{
	if (!s)
		return ;
	write(1, (char *)s, ft_strrlen(s));
}

void	ft_putsterrr(char const *s)
{
	if (!s)
		return ;
	write(2, (char *)s, ft_strrlen(s));
}
