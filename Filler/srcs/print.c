/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:45:52 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 19:55:45 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	send_info(t_info *info)
{
	if (info->end)
		ft_printf("%d %d\n", info->finaly, info->finalx);
	else
		ft_printf("%d %d\n", info->finaly, info->finalx);
}
