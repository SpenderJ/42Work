/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_override_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:45:37 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 14:21:36 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_z(t_params *arg)
{
	arg->flags[J] = 0;
	arg->flags[LL] = 0;
	arg->flags[L] = 0;
	arg->flags[H] = 0;
	arg->flags[HH] = 0;
}

void	ft_is_j(t_params *arg)
{
	arg->flags[LL] = 0;
	arg->flags[L] = 0;
	arg->flags[H] = 0;
	arg->flags[HH] = 0;
}

void	ft_is_ll(t_params *arg)
{
	arg->flags[L] = 0;
	arg->flags[H] = 0;
	arg->flags[HH] = 0;
}

void	ft_is_l(t_params *arg)
{
	arg->flags[H] = 0;
	arg->flags[HH] = 0;
}

void	ft_is_h(t_params *arg)
{
	arg->flags[HH] = 0;
}
