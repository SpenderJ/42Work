/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:19:29 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 17:19:32 by jebossue         ###   ########.fr       */
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
