/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_override_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:31:04 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 14:21:56 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*ft_general_overrides(t_params *arg)
{
	if (arg->flags[PLUS] && arg->flags[SPACE])
		arg->flags[SPACE] = 0;
	if (arg->flags[MINUS] && arg->flags[ZERO])
		arg->flags[ZERO] = 0;
	ft_override_length(arg);
	return (arg);
}

void		ft_override_params_d(t_params *arg, long long nb)
{
	if (arg->flags[SPACE] && arg->flags[PLUS])
		arg->flags[SPACE] = 0;
	if (arg->flags[SPACE] && nb < 0)
		arg->flags[SPACE] = 0;
	if (arg->flags[PLUS] && nb < 0)
		arg->flags[PLUS] = 0;
	if (arg->flags[ZERO] && arg->flags[PREC] && arg->width)
		arg->flags[ZERO] = 0;
}

void		ft_override_length(t_params *arg)
{
	if (arg->flags[Z])
		ft_is_z(arg);
	else if (arg->flags[J])
		ft_is_j(arg);
	else if (arg->flags[LL])
		ft_is_ll(arg);
	else if (arg->flags[L])
		ft_is_l(arg);
	else if (arg->flags[H])
		ft_is_h(arg);
	else
		;
}
