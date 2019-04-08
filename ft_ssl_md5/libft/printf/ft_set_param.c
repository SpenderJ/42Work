/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:23:53 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:23:56 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_param(t_arg *param)
{
	param->param_good = FAL;
	param->sharp = FAL;
	param->null = FAL;
	param->minus = FAL;
	param->plus = FAL;
	param->space = FAL;
	param->param_good = FAL;
	param->sharp = FAL;
	param->is_width = FAL;
	param->width = 0;
	param->is_pre = FAL;
	param->precision = 0;
	param->ln_block = 0;
	param->nbr_utf8_char = 0;
	param->len = none;
	param->is_spec = FAL;
	param->spec = no;
	param->specifier = 0;
}
