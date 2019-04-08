/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:23:35 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:23:36 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_free_param(t_arg *param)
{
	if (param == NULL)
		return ;
	ft_free_param(param->next);
	free(param);
}

void	ft_free_printf(char *buff, t_arg *param)
{
	free(buff);
	ft_free_param(param);
}
