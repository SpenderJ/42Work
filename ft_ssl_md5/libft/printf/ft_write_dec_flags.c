/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:20:04 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 17:20:07 by jebossue         ###   ########.fr       */
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
