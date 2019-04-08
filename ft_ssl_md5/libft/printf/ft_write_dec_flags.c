/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:24:08 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:24:09 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_write_dec_plus(char *buff, int is_neg)
{
	*buff = is_neg == TRU ? '-' : '+';
	++buff;
	return (buff);
}

char	*ft_write_dec_space(char *buff)
{
	*buff = ' ';
	++buff;
	return (buff);
}
