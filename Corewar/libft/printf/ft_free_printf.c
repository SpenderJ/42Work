/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:18:47 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 17:18:50 by jebossue         ###   ########.fr       */
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
