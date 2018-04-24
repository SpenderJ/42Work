/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:49:56 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/30 14:58:39 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*ft_create_params(void)
{
	t_params	*arg;

	arg = (t_params *)malloc(sizeof(t_params));
	if (arg)
		return (arg);
	else
		return (NULL);
}

t_params	*ft_set_zero_params(t_params *arg)
{
	ft_bzero(arg, sizeof(t_params));
	return (arg);
}
