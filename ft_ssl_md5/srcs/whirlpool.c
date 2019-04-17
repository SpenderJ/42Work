/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whirlpool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:41:57 by juspende          #+#    #+#             */
/*   Updated: 2019/04/17 12:40:50 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_whirlpool.h"

void			whirlpool(t_ssl *ssl, t_ssl_flag *ssl_flag)
{
	uint64_t		*res;
	int				index;
	uint8_t			*digest;

	index = -1;
	res = NULL;
	digest = NULL;
	(void)ssl_flag;
	(void)ssl;
	ft_printf("Whirlpool option not implemeted yet\n");
	return ;
}
